#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

void print_ListNode(ListNode *head)
{
    ListNode *tmp = head;

    while (tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp -> link;
    }
    printf("NULL");
    
}

int main()
{
    ListNode *a; // *를 까먹으면 안돼!
    ListNode *b;

    // allocate dynamic memory
    a = (ListNode *)malloc(sizeof(ListNode));
    b = (ListNode *)malloc(sizeof(ListNode));

    a -> data = 10;
    a -> link = NULL;

    b -> data = 20;
    b -> link = NULL;

    a -> link = b; // connect a and b

    print_ListNode(a);
    return 0;
}