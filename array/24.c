#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
int main(){
   Node*head=malloc(sizeof(Node));

    head=(Node*)malloc(sizeof(Node));
    head->data=45;
    head->link=NULL;
    Node*current=malloc(sizeof(Node));
    current->data=98;
    current->link=NULL;
    head->link=current;
        printf("%d->data",head->link);
    
    return 0;


}