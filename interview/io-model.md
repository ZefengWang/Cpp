# IO 模型

## 阻塞io
顾名思义就是进行读写数据时，当资源未就绪时，发生阻塞（也就是等待）

## 非阻塞io
非阻塞io是指在资源未就绪时，立即返回（错误或者提示信息），此时编程模型常用轮询，缺点是消耗cpu资源（时间）

## 多路复用io
多路复用的理解，其实是当多个io请求需要在一个线程或者进程内完成。
先构建一张表，然后调用函数，有io就绪时返回，select，pselect，poll，epoll
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
## 异步io
## 信号驱动io
## 内存映射io