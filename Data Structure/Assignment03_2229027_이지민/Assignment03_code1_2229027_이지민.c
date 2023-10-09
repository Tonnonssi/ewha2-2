#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

void init(DlistNode *phead)
{
    phead -> llink = phead;
    phead -> rlink = phead;
}

void display(DlistNode *phead)
{
    DlistNode *p;
    for (p=phead -> rlink; p != phead; p = p -> rlink)
    {
        printf("<---| %x | %d | %x | --->\n", p->llink, p->data, p->rlink);
    }
    printf("\n");
}
// add
void dinsert_node(DlistNode *before, DlistNode *new)
{
    new -> llink = before;
    new -> rlink = before -> rlink;
    before -> rlink -> llink = new;
    before -> rlink = new;
}
// delete
void dremove_node(DlistNode *phead_node, DlistNode *removed)
{
    if (removed == phead_node) return;
    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);
}

int main()
{
    DlistNode head_node;
    DlistNode *p[10];

    init(&head_node);
    for(int i = 0; i < 5; i++)
    {
        p[i] = (DlistNode *)malloc(sizeof(DlistNode));
        p[i] -> data = i;
        dinsert_node(&head_node, p[i]);
    }

    //append in the front
    p[9] = (DlistNode *)malloc(sizeof(DlistNode));
    p[9] -> data = 9;
    dinsert_node(&head_node, p[9]);

    // append in the back
    p[7] = (DlistNode *)malloc(sizeof(DlistNode));
    p[7] -> data = 7;
    dinsert_node(head_node.llink, p[7]);

    display(&head_node);
}