#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
int main(){
    void add_at_end(head,67);
}
 void add_at_end(Node*head,int data){
    Node *ptr,*temp;
    ptr=head;
    temp= malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;
 while(ptr->link!=NULL){
    ptr=ptr->link;
 }
 ptr->link=temp;
 }
 