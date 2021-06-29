# IO 模型

其实io操作分为两大类，同步io和异步io。

阻塞io，非阻塞io，io复用，信号驱动io 都是 **同步io** ，定义是阻塞进程直到io操作完成  
异步io是librt.so提供的aio接口，信号直到io操作完成才产生，期间并不会阻塞进程

## 阻塞io
顾名思义就是进行读写数据时，当资源未就绪时，发生阻塞（也就是等待）

## 非阻塞io
非阻塞io是指在资源未就绪时，立即返回（错误或者提示信息），此时编程模型常用轮询，缺点是消耗cpu资源（时间）

## 多路复用io
多路复用的理解，其实是当多个io请求需要在一个线程或者进程内完成。
先构建一张表，然后调用函数，有io就绪时返回，select，pselect，poll，epoll

select，pselect，poll等函数均可被信号打断返回errno为EINTR
此时使用pselect可以屏蔽一些信号字，增强程序健壮性

```C
/* According to POSIX.1-2001, POSIX.1-2008 */
#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int nfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, struct timeval *timeout);

void FD_CLR(int fd, fd_set *set);
int  FD_ISSET(int fd, fd_set *set);
void FD_SET(int fd, fd_set *set);
void FD_ZERO(fd_set *set);

#include <sys/select.h>

int pselect(int nfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, const struct timespec *timeout,
            const sigset_t *sigmask);
```

下面来看一个select的例子
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO "select.fifo"

char buf[100];
int main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;
	int fd,i, max;
	/* Watch stdin (fd ) to see when it has input. */
	if ( mkfifo(FIFO, S_IRUSR|S_IWUSR) != 0)
	{
		perror("create failed");
	}

	fd = open(FIFO,O_RDWR);
	printf("fd is %d\n", fd);
	if (fd < 0) {
		perror("open failed");
		return -1;
	}
	max = fd +1;
	FD_ZERO(&rfds);
	//FD_SET(0, &rfds);
	FD_SET(fd, &rfds);

	/* Wait up to five seconds. */

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	while (1){
		retval = select(max, &rfds, NULL, NULL, &tv);
		/* Don't rely on the value of tv now! */

		if (retval == -1)
			perror("select()");
		else if (retval)
			printf("Data is available now. retval: %d\n", retval);
		/* FD_ISSET(0, &rfds) will be true. */
		//else
		//printf("No data within five seconds.\n");
		for (i = 0; i < max; ++i)
		{
			if (FD_ISSET(i, &rfds)){
				read(i, buf, 100);
				printf("%s\n", buf);
				break;
			}
		}
	}
	close(fd);
	//unlink(FIFO);
	exit(EXIT_SUCCESS);
}
```
在bash执行命令
```bash
while true; do echo "hello" > select.fifo ; sleep 1; echo "write";done
```
再来看一个poll的例子
```C
#include  <unistd.h>
#include  <sys/types.h>       /* basic system data types */
#include  <sys/socket.h>      /* basic socket definitions */
#include  <netinet/in.h>      /* sockaddr_in{} and other Internet defns */
#include  <arpa/inet.h>       /* inet(3) functions */
 
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
 
 
#include <poll.h> /* poll function */
#include <limits.h>
 
#define MAXLINE 10240
 
#ifndef OPEN_MAX
#define OPEN_MAX 40960
#endif
 
#define NOTDEF
int
main(int argc, char **argv)
{
    int                 i, maxi, listenfd, connfd, sockfd;
    int                 nready;
    ssize_t             n;
    char                buf[MAXLINE];
    socklen_t           clilen;
    struct pollfd       client[OPEN_MAX];
    struct sockaddr_in  cliaddr, servaddr;
 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);//监听fd
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(6888);
 
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
    listen(listenfd, 1024);
 
    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for (i = 1; i < OPEN_MAX; i++)
        client[i].fd = -1;      /* -1 indicates available entry */
    maxi = 0;                   /* max index into client[] array */
/* end fig01 */
 
/* include fig02 */
    for ( ; ; ) {
        nready = poll(client, maxi+1, -1);//maxi表示client数组大小
 
        if (client[0].revents & POLLRDNORM) {   /*
            *new client connection
            *每次有新连接都会执行这个if语句，然后将新添加的链接调用accept来接受链接
            */
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);//accept函数返回了一个socketfd，
#ifdef  NOTDEF
            printf("new client: %s %d\n", (struct sockaddr *) &cliaddr, clilen);
#endif
 
            for (i = 1; i < OPEN_MAX; i++)//监视connfd是否可读、可写
                if (client[i].fd < 0) {
                    client[i].fd = connfd;  /* save descriptor */
                    break;
                }
            if (i == OPEN_MAX)
                //err_quit("too many clients");
                printf("too many clients\n");
 
            client[i].events = POLLRDNORM;//检测connfd是否可读
            if (i > maxi)
                maxi = i;               /* max index in client[] array */
 
            if (--nready <= 0)/*如果除了listen的client[0]被激活，其他事件没有没有被激活则nready是1
                *自减1后，为0，表示此次处理poll结束。继续下次监视。
                */
                continue;               /* no more readable descriptors */
        }
 
        for (i = 1; i <= maxi; i++) {    /* 第0个元素是处理listen的，处理其余accept的所有可读的connfd */
            if ( (sockfd = client[i].fd) < 0)//无效的fd
                continue;
            if (client[i].revents & (POLLRDNORM | POLLERR)) {//处理可读的connfd
                if ( (n = read(sockfd, buf, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                            /*4connection reset by client */
#ifdef  NOTDEF
                        printf("client[%d] aborted connection\n", i);
#endif
                        close(sockfd);
                        client[i].fd = -1;
                    } else
                        printf("read error");
                        //err_sys("read error");
                } else if (n == 0) {
                        /*4connection closed by client */
#ifdef  NOTDEF
                    printf("client[%d] closed connection\n", i);
#endif
                    close(sockfd);
                    client[i].fd = -1;
                } else
                    //writen(sockfd, buf, n);
                    write(sockfd, buf, n);
 
                if (--nready <= 0)
                    break;              /* no more readable descriptors */
            }
        }
    }
}
/* end fig02 */
```
下面是一个epoll的例子
```C
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define MAXLINE 10
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5555
#define INFTIM 1000

void setnonblocking(int sock)
{
    int opts;
    opts = fcntl(sock, F_GETFL);
    if(opts < 0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts = opts | O_NONBLOCK;
    if(fcntl(sock, F_SETFL, opts) < 0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }
}

int main()
{
    int i, maxi, listenfd, connfd, sockfd, epfd, nfds;
    ssize_t n;
    char line[MAXLINE];
    socklen_t clilen;
    //声明epoll_event结构体的变量,ev用于注册事件,数组用于回传要处理的事件
    struct epoll_event ev, events[20];
    //生成用于处理accept的epoll专用的文件描述符
    epfd = epoll_create(256);

    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    //把socket设置为非阻塞方式
    setnonblocking(listenfd);
    //设置与要处理的事件相关的文件描述符
    ev.data.fd = listenfd;
    //设置要处理的事件类型
    ev.events = EPOLLIN | EPOLLET;
    //注册epoll事件
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;

    char local_addr[] = "200.200.200.204";
    inet_aton(local_addr, &(serveraddr.sin_addr)); //htons(SERV_PORT);
    serveraddr.sin_port = htons(SERV_PORT);
    bind(listenfd, (sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(listenfd, LISTENQ);

    maxi = 0;
    for ( ; ; )
    {
        //等待epoll事件的发生
        nfds = epoll_wait(epfd, events, 20, 500);
        //处理所发生的所有事件
        for(i = 0; i < nfds; ++i)
        {
            if(events[i].data.fd == listenfd)
            {

                connfd = accept(listenfd, (sockaddr *)&clientaddr, &clilen);
                if(connfd < 0)
                {
                    perror("connfd<0");
                    exit(1);
                }
                setnonblocking(connfd);

                char *str = inet_ntoa(clientaddr.sin_addr);
                std::cout << "connect from " << str << std::endl;
                //设置用于读操作的文件描述符
                ev.data.fd = connfd;
                //设置用于注测的读操作事件
                ev.events = EPOLLIN | EPOLLET;
                //注册ev
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            }
            else if(events[i].events & EPOLLIN)
            {
                if ( (sockfd = events[i].data.fd) < 0) continue;
                if ( (n = read(sockfd, line, MAXLINE)) < 0)
                {
                    if (errno == ECONNRESET)
                    {

                        close(sockfd);
                        events[i].data.fd = -1;
                    }
                    else
                        std::cout << "readline error" << std::endl;
                }
                else if (n == 0)
                {
                    close(sockfd);
                    events[i].data.fd = -1;
                }
                //设置用于写操作的文件描述符
                ev.data.fd = sockfd;
                //设置用于注测的写操作事件
                ev.events = EPOLLOUT | EPOLLET;
                //修改sockfd上要处理的事件为EPOLLOUT
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
            }
            else if(events[i].events & EPOLLOUT)
            {
                sockfd = events[i].data.fd;
                write(sockfd, line, n);
                //设置用于读操作的文件描述符
                ev.data.fd = sockfd;
                //设置用于注测的读操作事件
                ev.events = EPOLLIN | EPOLLET;
                //修改sockfd上要处理的事件为EPOLIN
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
            }

        }

    }
}
```
## 信号驱动io
注册信号处理函数，待io数据就绪，产生信号，进程收到信号以后，阻塞读取数据
## 内存映射io
文件映射到内存，memcpy两个映射区域，实际上是内核数据到内核数据
## 异步io
异步io，aio，librt.so 异步io用的不是很多。