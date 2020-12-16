#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//case: 1 delting the first element from the lined list
struct Node * deletefirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head; 
}

//Case 2: delete at a index
struct Node * deleteatindex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
     p->next = q->next;
    
    free(q);
    return head; 
}
//Case 3: deleting the last node
struct Node * deletelast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next=NULL;
    
    free(q);
    return head; 
}

// Case 4: delete a value
struct Node * deletevalue(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->data!=value)
    {
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    
    free(q);
    return head; 
}


int main()
{
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    printf("Linked list before deletion\n");
    linkedListTraversal(head);
    
    //head = deletefirst(head);
    //head = deleteatindex(head,2);
    //head = deletelast(head);
    head = deletevalue(head,11);
    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    return 0;
}