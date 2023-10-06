#include <stdio.h>

#define MAX_DEGREE 101
#define MAX(a,b) (((a)>(b))?(a):(b))

/* Basic Form of Polynomial */

typedef struct 
{
    int degree;
    float coeff[MAX_DEGREE];
}polynomial;

polynomial poly_add_1(polynomial A, polynomial B)
{
    polynomial C;
    int Apos=0, Bpos=0, Cpos=0;

    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree = MAX(degree_a, degree_b);

    while (Apos <= A.degree && Bpos <= B.degree){
        if(degree_a > degree_b){
            C.coeff[Cpos++] = A.coeff[Apos++]; 
            degree_a --;
        }
        else if(degree_a == degree_b){
            C.coeff[Cpos++] = A.coeff[Apos++] + B.coeff[Bpos++];
            degree_a --; degree_b --;
        }
        else{
            C.coeff[Cpos++] = B.coeff[Bpos++];
            degree_b --;
        }
    }
    return C;
}

int main()
{
    polynomial a = {5, {1,2,3,4,5,8}}; /* 구조체는 이렇게도 받을 수 있다. */
    polynomial b = {4, {2,0,0,0,1}};
    polynomial c;
    c = poly_add_1(a,b);
}