#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

//0--stdin
//1--stdout
//2--stderr
int main()
{
    int fd = open("hello.txt", O_CREAT | O_WRONLY);
    close(STDOUT_FILENO);
    dup(fd); // 1
    write(STDOUT_FILENO, "Hello word\n", sizeof("Hello word\n"));
    return 0;
}
// int main () {
//     char* input_str = "Hello World\n";
//     //⭐️
//     //1 = STDOUT_FILENO
//     write(1, input_str, sizeof("Hello World\n"));

//     close(1);
//     return 0;
// }
