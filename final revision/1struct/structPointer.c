#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    int age;
    float weight;
    char name[30];
} person;

int main()
{
    int i, n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    //allocating memory
    person *ptr = malloc(n * sizeof(person));
    
    for(i = 0; i < n; i++)
    {
        printf("Enter first name and age respectively: ");
        // n number of name
        scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
    }

    printf("Displayiong Infroamtion:\n");
    for(i = 0; i < n; i++)
    {
        // \t
        printf("Name: %s\tAge: %d\n",(ptr+i)->name,(ptr+i)->age);
    }

    return 0;
}

// struct person
// {
//     int age;
//     float weight;
// };

// int main()
// {
//     struct person *personPtr, person1;
//     personPtr = &person1;

//     printf("Enter age: ");
//     scanf("%d", &personPtr->age);

//     printf("Enter weight: ");
//     scanf("%f", &personPtr->weight);

//     printf("Displayiong:\n");
//     // printf("Age: %d\n", (*personPtr).age);
//     // printf("Weight: %.2f", (*personPtr).weight);

//     printf("Age: %d\n", personPtr->age);
//     printf("Weight: %.2f", personPtr->weight);
//     return 0;
// }
