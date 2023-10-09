#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct 
{
    int list[MAX_LIST_SIZE];
    int length;
}ArrayListType;

// list initalization
void init(ArrayListType *L)
{
    L -> length = 0;
}

// check empty of full
int is_empty(ArrayListType *L)
{
    return L -> length == 0;
}

int is_full(ArrayListType *L)
{
    return L -> length == MAX_LIST_SIZE;
}

// add
void add(ArrayListType *L, int pos, element item)
{
    if (!is_full(L) &&(pos >= 0) && (pos <= L->length))
    {
        int i;
        for(i=(L->length-1); i>=pos; i--)
            L -> list[i+1] = L -> list[i];
        L -> list[pos] = item;
        L -> length++;
    }
}

// delete & return the item that I deleted
element delete(ArrayListType *L, int pos)
{
    int i;
    element item;

    if(pos < 0 || pos >= L->length) printf("Position Error.");
    
    item = L -> list[pos];

    for (i=pos; i <= (L ->length-1); i++)
        L ->list[i] = L->list[i+1];
    L->length --;
    return item;
}

int main()
{
    ArrayListType lst;
    init(&lst);

    add(&lst, 0, 1);
    add(&lst, 1, 2);
    add(&lst, 2, 5);
    add(&lst, 3, 6);
    add(&lst, 4, 7);
    add(&lst, 5, 8);
    add(&lst, 6, 9);

    for (int i = 0; i < lst.length; i++)
        printf("%d ", lst.list[i]);
    printf("\n");

    delete(&lst, 4);

    for (int i = 0; i < lst.length; i++)
        printf("%d ", lst.list[i]);
    printf("\n");

}