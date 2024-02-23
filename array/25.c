#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

int main()
{
    // Create the head node.
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 45;
    head->link = NULL;

    // Create the current node.
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = 98;
    current->link = NULL;

    // Link the head node to the current node.
    head->link = current;

    // Print the data of the head node.
    printf("%d\n", head->link);

    return 0;
}
