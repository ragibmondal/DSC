#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int p;
    char q[50]; // Changed from string to char array
    float r;
    struct node *next;
};

int main() {
    typedef struct node node;
    node* a = (node*)malloc(sizeof(node)); // Casted the malloc return type
    node* b = (node*)malloc(sizeof(node));
    node* c = (node*)malloc(sizeof(node));
    node* d = (node*)malloc(sizeof(node));
    node* e = (node*)malloc(sizeof(node));
    a->p = 3;
    strcpy(a->q, "Pom"); // Used strcpy to copy string
    a->r = 3.2;
    a->next = b;

    b->p = 4;
    strcpy(b->q, "Rom"); // Used strcpy to copy string
    b->r = 4.2;
    b->next = c;

    c->p = 5;
    strcpy(c->q, "Dom"); // Used strcpy to copy string
    c->r = 5.2;
    c->next = d;

    d->p = 6; // Added a missing semicolon
    strcpy(d->q, "Lom"); // Used strcpy to copy string
    d->r = 6.2;
    d->next = e;
    
    e->p = 7;
    strcpy(e->q, "Mom"); // Used strcpy to copy string
    e->r = 7.2;
    e->next = NULL;

    node* ptr;
    ptr = a;
    while(ptr != NULL) {
        printf("%d %s %f\n", ptr->p, ptr->q, ptr->r); // Changed %c to %s for string
        ptr = ptr->next;
    }

    free(a); // Freeing allocated memory
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}
