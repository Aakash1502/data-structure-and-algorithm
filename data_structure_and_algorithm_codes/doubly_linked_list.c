#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void linkedListTraversalreverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
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
    head->prev = NULL;

    // Link second and third nodes
    second->data = 11;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    fourth->prev = third;

    linkedListTraversal(head);

    printf("Reverse linked list\n");
    linkedListTraversalreverse(fourth);
    return 0;
}