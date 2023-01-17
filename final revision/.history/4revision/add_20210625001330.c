#include <stdio.h>

int *add(int a, int b)
{
    int result = a + b;
    return &result;
}

int main(void){
    int *result = add(3,5);
int *result = add(4,4);
    printf("3 + 5 = %d\n", *result);
    printf("")

}