#include <stdio.h>

typedef struct Student
{
    char name[50];
    int age;

} student;

//function
student getInfromation();

int main()
{
    student s;
    s = getInfromation();

    printf("Displaying Information\n");
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.age);

    return 0;
}

student getInfromation()
{
    student s1;

    printf("Enter name: ");
    scanf("%[^\n]%*c", s1.name);

    printf("Enter age: ");
    scanf("%d", &s1.age);

    return s1;
}
