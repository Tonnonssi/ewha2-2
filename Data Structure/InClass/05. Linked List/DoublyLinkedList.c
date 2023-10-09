#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlisNode{
    element data;
    struct DlisNode *llink;
    struct DlisNode *rlink;
} DlisNode;

void init(DlisNode *phead)
{
    phead -> llink = phead;
    phead -> rlink = phead;
}

void display(DlisNode *phead)
{
    DlisNode *p;
    for (p=phead -> rlink; p != phead; p = p -> rlink)
    {
        printf("<---| %x | %d | %x | --->\n", p->llink, p->data, p->rlink);
    }
    printf("\n");
}
// add
void dinsert_node(DlisNode *before, DlisNode *new)
{
    new -> llink = before;
    new -> rlink = before -> rlink;
    before -> rlink -> llink = new;
    before -> rlink = new;
}
// delete
void dremove_node(DlisNode *phead_node, DlisNode *removed)
{
    if (removed == phead_node) return;
    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);
}

int main()
{
    DlisNode head_node;
    DlisNode *p[10];

    init(&head_node);
    for(int i = 0; i < 5; i++)
    {
        p[i] = (DlisNode *)malloc(sizeof(DlisNode));
        p[i] -> data = i;
        dinsert_node(&head_node, p[i]);
    }
    dremove_node(&head_node, p[3]);
    display(&head_node);
}