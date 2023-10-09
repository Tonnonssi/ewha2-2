1
Introduction
This program implements a doubly linked list and allows adding and removing nodes from the doubly linked list.

Execution
Main Section
Refer to the for loop to implement the desired doubly linked list.
Add a new node you want through the dinsert_node function at the beginning or end.
Display the list using the display function.

Compile and execute the file.
Functions and Parameters
phead: Defined as DlistNode *phead, and anything referred to as phead follows this format.

DlistNode Structure: Implements a doubly linked list.

Init Function: Initializes a DlistNode, assigns phead to the llink and rlink, both pointing to itself.

Display Function: Prints <--- rlink | data | llink ---> using phead and a for loop to print.

Dinsert_node Function: Adds a new DlistNode. Takes a new node and the node after which the new node should be inserted.

dremove_node Function: Deletes a DlistNode. Takes phead_node and the removed node and disconnects the removed node's links and deallocates memory.

2
Introduction
This code takes two simple linked lists and merges them into one in ascending order, considering the sizes of each node's data.

Execution
Main Section
Implement ListNode A and B nodes using arrays.
If you want to swap A and B, simply change the elements in arrays a and b.

Compile and execute the file.
Functions and Parameters
init(ListNode **phead): Initializes a ListNode.
display(ListNode *head): Displays a ListNode.
insert_last(ListNode **phead, element data): Connects data at the bottom of the input ListNode.
make_ListNodeC(ListNode **C, ListNode *A, ListNode *B): Creates a new listnode C based on ListNode *A and ListNode *B.
3
Introduction
This code uses an additional structure called ListType to manage simple linked lists, storing head, tail, and length. It simplifies understanding as it doesn't require using double pointers (phead) when working with simple linked lists.

Execution
Main Section
Implements the list and adds nodes to list1 using functions like add, add_first, and add_last.
Deletes nodes using delete, delete_first, and delete_last functions.
Checks if a specific element is inside the list using is_in_list.
Retrieves the value at a specific position using the get_entry function.

Compile and execute the file.
Functions and Parameters
init(ListType *plist): Initializes plist by setting length, tail, and head.
is_empty(ListType *list): Returns 1 if list is empty (head is NULL), otherwise returns 0.
*get_node_at(ListType *list, int pos): Returns the node at position pos in the list.
insert_node(ListType *list, ListNode *p, ListNode *new): Inserts a new node after node p.
add(ListType *list, int pos, element data): Adds a node with data at the specified position in the list.
add_first(ListType *list, element data): Adds a new node at the beginning of the list.
add_last(ListType *list, element data): Adds a new node at the end of the list.
removed_node(ListType *list, ListNode *p, ListNode *removed): Disconnects and deallocates memory for the removed node.
delete(ListType *list, int pos): Deletes the node at the specified position in the list.
delete_first(ListType *list): Deletes the first node in the list.
delete_last(ListType *list): Deletes the last node in the list.
is_in_list(ListType *list, element item): Checks if an item exists in the list and returns true if found, false otherwise.
get_entry(ListType *list, int pos): Returns the value of the node at the specified position in the list.
display(ListType *list): Prints the values of all nodes in the list.