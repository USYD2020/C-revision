#include <stdio.h>
#include <unistd.h>

int main(){
    printf("a\n");
    printf("b\n");
    execl("./hello",0);
    printf("c\n");
    printf("d\n");

    return 0;
}
