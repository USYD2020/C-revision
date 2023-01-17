#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void foo()
{
    FILE *fp = fopen("doesn't exit", "r");
}

int main()
{
    foo();
    //positive value file not found
    printf("errno: %d\n", errno);
    perror("");

    errno = 0;
    int x = 5;
    printf("errno: %d\n", errno); // 0
    perror("");

    void *data = (void*)malloc(1);
    printf("errno: %d\n", errno);//? !=0
    perror("");

    free(data);
    printf("errno: %d\n", errno);//? !=0
    perror("");

    FILE *fp2 = fopen("doexist.txt", "r");
    printf("errno: %d\n", errno);
    perror("");

    return 0;
}
