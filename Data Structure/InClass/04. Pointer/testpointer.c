#include<stdio.h>

int main()
{
    int a = 10;
    int *p1; // allocate pointer 
    p1 = &a;

    printf("%d\n", p1);
    printf("%d\n", *p1);

    int b = *p1++;

    printf("%d\n", p1);
    printf("%d\n", *p1);
    printf("%d\n", b);
    return 0;
}