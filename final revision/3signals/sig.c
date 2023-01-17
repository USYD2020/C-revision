#include <stdio.h>

#include <signal.h>
#include <unistd.h>

/*
C's volatile keyword is a qualifier that is applied to a variable when it is declared. 
It tells the compiler that the value of the variable may change at any time
--without any action being taken by the code the compiler finds nearby.
*/
volatile int interrupted = 0;
//signal handler
void impatient(int arg)
{
    interrupted = 1;
}

int main()
{
    void (*variable)(int) = impatient;
    //call signal
    signal(SIGINT, variable);// setting up
    printf("do something\n");
    // ctrl-c
    while(!interrupted)
        usleep(5);
    printf("you didn't like waiting\n");
    printf("program terminated\n");
    return 0;
}


