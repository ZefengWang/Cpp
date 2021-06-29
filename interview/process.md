# 进程

## 进程环境
---
### 进程入口
操作系统执行一个程序，在执行main函数之前，先调用exec，执行一个启动过程 

    * 设置程序起始地址
    * 从内核获取命令行参数和环境变量
    * 调用main函数

### 进程终止
    * 从main返回 return
    * exit
    * _exit
    * 最后一个线程返回
    * 最后一个线程调用_pthread_exit

异常终止

    * abort
    * 信号
    * 最后一个线程对取消请求做出响应

**返回函数**  
exit， _exit, _Exit  
atexit
### 命令行参数
main的原型 
```C
int main(int argc, char *argv[]);  
```
iso C和POSIX规定 argv[argc]==NULL
### 环境表
同命令行参数
但是早期C支持main第三个参数是环境表，但是iso C规定了main只有2参数，  
而第三个参数比起全局变量并没有带来多大的性能提升，所以POSIX最后也支持main带两个参数  
环境变量形式为  
NAME=value  
如果要访问整个环境表使用指针 environ  
声明原型如下  
```C
extern char **environ;
```
### 内存布局
代码段，可共享，只读  
初始化的全局数据段（以上两段由exec族函数从可执行文件中读取）  
未初始化的数据（bss）由exec赋值为0
堆，向上生长，动态分配
共享内存和内存映射区（堆栈之前）
栈（系统管理）
命令行参数和环境变量
### 共享库
即动态库
运行时开销，共享库第一次被调用时加载，若已加载，则不需要额外时间加载到内存中
### 动态分配
`malloc`  
`calloc`
`realloc`
### 环境变量
getenv
### setjmp longjmp
```C
#include <setjmp.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int i = 0;
	jmp_buf env;
	printf("return setjmp:%d, i: %d\n", setjmp(env), i);
	sleep(1);
	i = 1;
	longjmp(env,1);

	return 0;
}
```

### 进程资源限制
getrlimit  
setrlimit  

## 进程控制
---

### 进程标识
```C
pid_t
getpid
getppid
getuid
geteuid
getgid
getegid
```
### **``fork``**
创建子进程，返回2次，子进程pid是0，父进程则返回子进程的pid。pid为0的进程是内核交换进程。  
父子进程共享的数据只有代码段。堆栈是副本，使用cow，写时复制，避免一开始fork之后紧接着调用exec之前发生数据拷贝  
**文件共享**  
文件描述符也会共享，包括打开的文件，文件表项，v节点，i节点等。文件偏移也是共享的
|共享的内容||
---
|组id，用户id，有效组，有效用户|
|附属组|
|进程组|
|会话id|
|控制终端|
|用户id标识|
|work dir|
|root dir|
|文件模式创建屏蔽字|
|信号屏蔽字|
|文件的标志|
|环境|
|共享存储段|
|存储映射|
|资源限制|

|不同的地方|
---
|pid|
|fork返回值|
|ppid|
|子进程的tms_utime不同|
|子进程不继承文件锁|
|子进程未处理的闹钟被清除|
|子进程未处理的信号集设置为空集|
### **``vfork``**
会保证子进程先行运行，在子进程调用了exec或者exit以后，父进程才会继续运行，vfork不复制父进程的资源，子进程的目的就是为了执行exec，尽管fork使用了cow，但是不复制比部分复制还是会快一些。

### **``exit``**
不论进程是正常退出还是异常退出，最后总会执行同一段清除代码  
exit()函数的参数其实就是进程的退出状态  
父进程要终止时，内核会检查活动进程是否是该进程的子进程，如果是则将其父进程pid改为1，确保其有父进程  
以前是init，现在可能是systemd  
父进程未回收子进程，则该进程变为僵死进程，也叫僵尸进程，zombie，ps命令下Z标识  
父进程结束的子进程会被收养变成孤儿进程

### **``wait`` 和 ```waitpid```**
子进程死了，内核会告诉其父进程，通过发送信号`SIGCHLD`，父进程接受到信号默认操作是忽略
但是一般处理是调用`wait`获取（僵死）子进程的pid，并返回
但是如果在没有收到信号时调用`wait`，会有以下三种情况

1. 所有子进程都在运行，没有僵死子进程，则父进程阻塞
2. 有僵死子进程等待父进程回收资源，`wait`返回僵死子进程的pid
3. 没有子进程，`wait`立马出错并返回

`wait`的返回值可使用/sys/wait.h中的WI打头的宏来判断，其中有一个`WCOREDUMP`许多都支持
waitpid有一个参数`option`可使程序不阻塞
### **``waitid``**
### **``wait3``和``wait4``**
回收资源
### **竞争条件**
ipc以及信号
### **``exec``**
