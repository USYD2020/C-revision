#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2] = {-1,-1};  //将fd和rfd初始值都设为-1
    int rfd[2] = {-1,-1};
    
    int ret = pipe(fd);
    if (ret == -1) // 如果pipe函数返回-1，pipe失败
    {
        perror("error");
        return 1;
    }
    
    ret = pipe(rfd);
    if(ret == -1){
        perror("error pipe2");
        return 2;
    }
    printf("fd: %d %d\n", fd[0],fd[1]);
    printf("rfd: %d %d\n", rfd[0],rfd[1]);


    char buffer_in[20];
    ssize_t nread2 = read(0, buffer_in, 20); //读取用户输入
    buffer_in[nread2] = '\0';

    int pid = fork(); //fork 进程
    if (pid == 0)
    {
        //child
        //子进程关闭fd的写入，及rdf的读取；因为子进程端fd只用于读取，rfd只用于写入
        close(fd[1]);
        close(rfd[0]);

        char buffer[20];
        printf("child is waiting for input...\n");
        //从管道缓存区读取信息
        ssize_t nread = read(fd[0], buffer, 19);
        if(nread == -1)
        {
            perror("child read error\n");
        }else{
            buffer[nread] = '\0';
            printf("nread: %zd\n",nread);
            printf("%s\n",buffer);


            char response[25];
            snprintf(response, 25, "ACK:%s",buffer); //格式化字符串
            size_t resp_len = strlen(response) + 1;
            ssize_t nwritten = write(rfd[1], response, resp_len); 
            if(nwritten == -1){
                perror("child write error");
            }else{
                printf("child wrote %zd bytes\n", nwritten);
            }
        }
        close(fd[0]);
        close(rfd[1]);
    }else{
        sleep(2);

        close(fd[0]);
        close(rfd[1]);

        //parent
        printf("child pid is %d\n", pid);
        //向子进程写入
        ssize_t nwritten = write(fd[1], buffer_in, strlen(buffer_in));
        if(nwritten == -1){
            perror("parent write error");
        }else{
            printf("%zd bytes written\n",nwritten);

            char child_response[25];
            ssize_t nread = read(rfd[0], child_response, 25);

            if(nread == -1){
                perror("parent read error\n");
            }else{
                child_response[nread] = '\0';

                char expected[25];
                snprintf(expected, 25, "ACK:%s", buffer_in);
                printf("parent received: %s [ %d ]\n", child_response, strncmp(expected, child_response, strlen(expected))); //比较结果
            }
        }
        printf("parent has completed\n");

        close(fd[1]);
        close(rfd[0]);
    }
    return 0;
}
