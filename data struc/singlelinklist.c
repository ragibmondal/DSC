#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main(){
    typedef struct node node;
    node *head,*second,*third,*ptr;
    head=malloc(sizeof(node));
    second=malloc(sizeof(node));
    third=malloc(sizeof(node));

    head->data=5;
    second->data=6;
    third->data=7;
    head->next=second;
    second->next=third;
    third->next=NULL;

    ptr=head;
     while(ptr!=NULL){
        printf("%d \t",ptr->data);
        ptr=ptr->next;
     }

    return 0;
}