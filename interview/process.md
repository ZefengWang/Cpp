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
malloc
calloc
realloc
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
