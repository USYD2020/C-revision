#include <stdio.h>

typedef struct Student
{
    char name[50];
    int age;
} student;

//function
void display(student s);

int main()
{
    student s1;

    printf("Enter name: ");
    //read string input from the user yntil \n is entered
    // \n is discarded
    scanf("%[^\n]%*c",s1.name);

    printf("Enter age: ");
    scanf("%d", &s1.age);

    display(s1);
    return 0;
}

void display(student s)
{
    printf("display information\n");
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
}
