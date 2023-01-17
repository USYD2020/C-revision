#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void output(int signal)
{
    printf("Hello Wrold");
}

void leave(int signal)
{
    exit(0);
}

int main()
{
    signal(SIGUSR1, output);// 当接收到SIGUSER1时，执行output函数
    int pid = getpid(); //获取自身pid
    signal(SIGINT, leave); //当收到SIGINT信号，执行leave函数

    while(1)
    {
        if(pid == 0)
        {

        }else{
            kill(pid, SIGUSR1);//向自己发送SIGUSR1
        }
        sleep(2);
        
    }
    return 0;
}
