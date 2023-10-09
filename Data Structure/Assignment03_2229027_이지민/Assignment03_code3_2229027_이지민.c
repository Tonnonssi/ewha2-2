#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    int length;
} ListType;

void init(ListType *plist)
{
    plist -> length = 0;
    plist -> head = plist -> tail = NULL;
}

int is_empty(ListType *list){
    if (list->head == NULL) return 1;
    else return 0;
}

ListNode *get_node_at(ListType *list, int pos)
{
    int i;
    ListNode *tmp = list -> head;
    if (pos < 0) return NULL;
    for(i =0; i < pos; i++)
        tmp = tmp -> link;
    return tmp;
}

void insert_node(ListType *list, ListNode *p, ListNode *new)
{
    if (list -> head == NULL){
        // blank list
        new -> link = NULL;
        list -> head = new;
        list -> tail = new;
    }
    else{
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

void add(ListType *list, int pos, element data)
{
    ListNode *p;
    if ((pos >=0) && (pos <= list -> length)){
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));

        if (node == NULL) 
            // error("Memory allocation error.");
            printf("Memory allocation error.");

        node -> data = data;
        p = get_node_at(list, pos-1);
        insert_node(list, p, node);
        list -> length ++;
    }
}

void add_first(ListType *list, element data)
{   
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node -> data = data;

    if (list -> head == NULL){
        // blank list
        new_node -> link = NULL;
        list -> head = new_node;
        list -> tail = new_node;
    }
    else{
        new_node -> link = list -> head;
        list -> head = new_node;

    }
    list -> length ++;
}

void add_last(ListType *list, element data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node -> data = data;
    new_node -> link = NULL;

    if (list -> head == NULL){
        // blank list
        list -> head = new_node;
        list -> tail = new_node;
    }
    else{
        ListNode *p = list -> tail;
        
        p -> link = new_node;
        list -> tail = new_node;
    }
    list -> length ++;
}
void removed_node(ListType *list, ListNode *p, ListNode *removed)
{
    if (list -> head == NULL) printf("The list is blank.\n");
    else{
        p -> link = removed -> link;
        free(removed);
    }
}

void delete(ListType *list, int pos)
{
    if(!is_empty(list) && (pos >= 0) && (pos < list -> length)) {
        ListNode *p = get_node_at(list, pos-1);
        ListNode *removed = get_node_at(list, pos);
        removed_node(list, p, removed);
        list -> length --;
    }
}

void delete_first(ListType *list)
{
    if (!is_empty(list)){
        ListNode *removed = list -> head;
        list -> head = removed -> link;
        free(removed);
    }
    list -> length --;
}

void delete_last(ListType *list)
{
    if(!is_empty(list)){
        ListNode *removed = list -> tail;
        ListNode *p = get_node_at(list, list->length -2);

        list -> tail = p;
        p -> link = NULL;
        free(removed);
    }
    list -> length --;
}

int is_in_list(ListType *list, element item)
{
    ListNode *p;
    p = list -> head;

    while(p != NULL){
        if (p -> data == item) break;
        p = p -> link;
    }
    if (p == NULL) return false;
    else return true;
}

element get_entry(ListType *list, int pos)
{
    ListNode *p;
    if (pos >= list -> length) 
        printf("Position Error");
    p = get_node_at(list, pos);
    return p -> data;
}

void display(ListType *list)
{
    int i;
    ListNode *node = list -> head;
    printf("( ");
    for (i = 0; i < list -> length; i ++){
        printf("%d ->", node -> data);
        node = node -> link;
    }
    printf(" )\n");
}

int main()
{
    ListType list1;
    init(&list1);
    add_first(&list1, 20);
    add_last(&list1, 30);
    add_first(&list1, 10);
    add_last(&list1, 40);
    add(&list1, 2, 70);
    display(&list1);

    delete(&list1, 2);
    delete_first(&list1);
    delete_last(&list1);
    display(&list1);

    printf("%s\n", is_in_list(&list1,20) == true ? "TRUE" : "FALSE");
    printf("%d\n", get_entry(&list1, 0));
    
    return 0;
}

