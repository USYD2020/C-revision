#include <stdio.h> 
#include <stdlib.h>

typedef int (*func_ptr) (int, int);

int add(int a , int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

// int calc(func_ptr func, int a, int b) {
//     return func(a, b);
// }

func_ptr f1() {
    //if(strcmp(.....) ,)
    return add;
    // return mult;
}

func_ptr f2() {
    return mult;
}

int main() {
    int a = 10; 
    int b = 8;
    // int result = calc(mult, a, b);
    func_ptr fun1 = f1();
    func_ptr fun2 = f2();
    int result1 = fun1(a, b); //18
    printf("%d\n", result1);
    int result2 = fun2(a, b);
    printf("%d\n", result2); //20
    return 0;
}
