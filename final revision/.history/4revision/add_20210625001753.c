#include <stdio.h>

int add(int a, int b)
{
    int result = a + b;
    return &result;
}

int main(void)
{
    int result = add(3, 5);
    int result2 = add(4, 4);
    printf("3 + 5 = %d\n", *result);
    printf("4 + 4 = %d\n", *result2);

    return 0;
}
// add.c:6:13: warning: address of stack memory associated with local variable 'result' returned
//       [-Wreturn-stack-address]
//     return &result;
//             ^~~~~~
// 1 warning generated.
// 3 + 5 = 8