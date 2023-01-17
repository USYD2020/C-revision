#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status, i;
    
    if (fork() == 0)
    {
        //getpid函数返回当前进程pid
        printf("This is child process. pid = %d\n", getpid());
        exit(1);
    }
    else{
        sleep(1);
        printf("This is parent process, wait for child process\n");
        pid = wait(&status);
        //帮助我们返回状态值
        i = WEXITSTATUS(status);
        printf("child's pid = %d. exit status = %d\n",pid , i);
    }
    return 0;
}
