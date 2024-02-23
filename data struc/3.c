#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
int main(){
    Node *head=malloc(sizeof(Node));
    head->data=45;
    head->link=45;
    Node *current=malloc(sizeof(Node));
    current->data=98;
    current->link=NULL;
    head->link=current;
    current=malloc(sizeof(Node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    printf("%d",head->link->link->data);
    return 0;
}