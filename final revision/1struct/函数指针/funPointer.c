#include <stdio.h>
int Max(int,int); //函数声明

int Max(int x, int y) //定义Max函数
{
    int z;
    if (x > y)
    {
        z = x;
    }
    else{
        z = y;
    }
    return z;
}
int main(void)
{
    int (*ptr)(int, int); //定义一个函数指针
    int a, b, c;
    ptr = Max; //把函数Max赋给指针变量ptr，使ptr指向max函数

    printf("please enter a and b:");
    scanf("%d%d",&a, &b);
    c = (*ptr)(a,b); //通过函数指针调用Max函数

    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    return 0;
}

