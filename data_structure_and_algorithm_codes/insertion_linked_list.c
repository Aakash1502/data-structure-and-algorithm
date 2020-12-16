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

int main()
{
    struct Node *insertion_1;
    struct Node *insertion_between;
    struct Node *insertion_end;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    insertion_1 = (struct Node *)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    insertion_between = (struct Node *)malloc(sizeof(struct Node));
    insertion_end = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //insertion in the beginning
    insertion_1->data = 1;
    insertion_1->next = head;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = insertion_between;

    //insertion after second(in between)
    insertion_between->data = 2;
    insertion_between->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = insertion_end;

    //insertion at end
    insertion_end->data = 20;
    insertion_end->next = NULL;

    linkedListTraversal(insertion_1);
    return 0;
}