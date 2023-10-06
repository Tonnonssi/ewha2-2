#include <stdio.h>
#include <string.h>

#define MAX_TERMS 101

struct 
{
    float coef;
    int expon;
}terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,5}, {6,1}, {3,0}};

int avail=6;

char compare(int a, int b){
    if (a > b) return '>';
    else if (a == b) return '=';
    else return '<';
}

void attach(float coef, int expon)
{
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef; 
    while ((As <= Ae)&&(Bs <= Be))
    {
        switch (compare(terms[As].expon, terms[Bs].expon)) // swith case break 기억하기 
        {
        case '>':
            attach(terms[As].coef, terms[As].expon);
            As ++; break;
        
        case '=':
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef) attach(tempcoef, terms[As].expon);
            As ++; Bs ++; break;
        
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs ++; break;
        }
    }
    /* 
    for문이 존재하는 이유 
    A, B의 가장 작은 차수가 다르면 더 작은 차수를 갖고 있는 다항식의 계수를 전부 살펴보기 전에 while문이 종결된다. 
    따라서 A나 B 중에 차수가 작아 미처 확인하지 못한 부분을 뒤로 더해주는 것이다.
    */
    for (;As<=Ae;As++) attach(terms[As].coef, terms[As].expon);
    for (;Bs<=Be;Bs++) attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail - 1; // nanimono..
}

int main()
{
    int Cs, Ce;
    poly_add2(0,2,3,5,&Cs,&Ce);
    return 0;
}