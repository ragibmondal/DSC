/creating one node
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int data;
    struct node *link;
}Node;
int main(){
    Node *head =NULL;
    head=(Node*)malloc(sizeof(Node));
    head->data=45;
    head->link=NULL;
    printf("%d \n",head->data);
    return 0;
}
