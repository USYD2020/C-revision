#include<stdio.h>

int int_com(*void a, *void b)
{
    int* a_ptr = (int*) a;
    int* b_ptr = (int*) b;
    return *a_ptr - *b_ptr;
}

int str_com(*void a, *void b)
{
    
}

void bubble_sort(void* elements, size_t n_elements, size_t size_element, int (*cmp)(const void*, const void*))
{


}
