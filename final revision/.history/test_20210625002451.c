#include <stdio.h>

int main(void)
{
    int c = "QUOKKA"[3];
    char k[] = {0, 98, 99, 98, 0};
    k[0] = c;
    printf("%s\n", (char *)k);
    
}