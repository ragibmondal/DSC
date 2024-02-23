#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
int main(){
   Node*head=NULL;

    head=(Node*)malloc(sizeof(Node));
    head->data=5;
    head->link=NULL;
   
        printf("%d->data",head->data);
    
    return 0;


}