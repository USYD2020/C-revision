#include <stdio.h>

int add(int a, int b)
{
    int result = a + b;
    return result;
}

int main(void)
{
    int c = "QUOKKA"[3];
char k[] = { 0, 98, 99, 98, 0 }; k[0] = c;
printf("%s\n", (char*)k);

}
// add.c:6:13: warning: address of stack memory associated with local variable 'result' returned
//       [-Wreturn-stack-address]
//     return &result;
//             ^~~~~~
// 1 warning generated.
// 3 + 5 = 8