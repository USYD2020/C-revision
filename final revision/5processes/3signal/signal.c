#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

static pid_t child;
static pid_t parent;
static int flag;

void sayHello(int signal)
{
    printf("Hello\n");
    //向子进程发送SIGINT
    kill(child, SIGINT);
    flag = 0;
}

void sayHandsome(int signal)
{
    printf("Oliver is sayHandsome\n");
    flag = 0;
}

int main()
{
    flag = 1;
    pid_t pid = fork();
    child = pid;
    if (pid < 0)
    {
        perror("Unable to fork");
        return 1;
    }
    if(pid == 0)
    {
        printf("This is child process\n");
        kill(parent, SIGINT); //向父进程发送SIGINT
        signal(SIGINT, sayHandsome); //等待接受SIGINT
        
        while(flag == 1)
        {
            sleep(1);
        }
    }else{
        printf("This is parent process\n");
        signal(SIGINT, sayHello); //等待接收SIGINT
        while(flag == 1)
        {
            sleep(1);
        }
        wait(NULL);
    }
}
