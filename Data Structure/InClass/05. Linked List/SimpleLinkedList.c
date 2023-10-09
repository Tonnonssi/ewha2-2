#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void insert_first(ListNode **phead, ListNode *new)
{
    if (*phead == NULL){
        new -> link = NULL;
        *phead = new;
    } 
    else{
        new -> link = *phead; // ! *head -> link
        *phead = new;
    }
}

void insert(ListNode **phead, ListNode *p, ListNode *new)
{
    if (*phead == NULL){
        new -> link = NULL;
        *phead = new;
    } 
    else {
        if (p == NULL){
            printf("The preceding node cannot be NULL.\n");
            exit(1);
        }
        else{
            new -> link = p -> link;
            p -> link = new;
        }
    }
}

void insert_last(ListNode **phead, ListNode *new)
{
    if (*phead == NULL){
        new -> link = NULL;
        *phead = new;
    } 
    else{
        new -> link = NULL;
        struct ListNode *last = *phead;
        while(last -> link != NULL) //caution
            last = last -> link;
        last -> link = new;
    }
}
