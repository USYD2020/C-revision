#include <stdio.h>
#include <unistd.h>

int main(){
    // pid_t 可以直接用int代替
    // int pid = fork();
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("This is the child process\n");
        //execl();
    }
    if (pid > 0)
    {
        printf("This is the parent process\n");
    }
}
