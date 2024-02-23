#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    typedef struct node node;
    node *head=NULL,*cur,*ptr,*temp;
    int a[5]={1,2,3,4,5};

    for(int i=0; i<=4;i++){
        temp=malloc(sizeof(node));
        temp->data=a[i];
        temp->next=NULL;

        if(head==NULL){
            head=temp;
            cur=temp;
        }
        else{
            cur->next=temp;
            cur=cur->next;
        }

    }
    ptr=head;
    while(ptr!=NULL){
        printf("%d \t",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}