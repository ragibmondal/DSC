#include<stdio.h>
#include<stdlib.h>

struct Node{

int data;
struct Node *next;
};

int main(){
typedef struct Node node;
node*head=NULL;
node*current=NULL;
node*temp=NULL;

int a[5]={5,6,7,8,9};

for(int i=0; i<5; i++){

temp=(node*)malloc(sizeof(node));
temp->data=a[i];
 temp->next=NULL;

if(head==NULL){

head=temp;
current=temp;
}

else{
current->next=temp;
current=current->next;
}



}

node*firstNode=NULL;
firstNode=(node*)malloc(sizeof(node));
firstNode->data=1;
firstNode->next=head;
head=firstNode;

node*middleNode=NULL;
middleNode=(node*)malloc(sizeof(node));
middleNode->data=1;
middleNode->next=NULL;
node*ptr=NULL;
ptr=head;
int pos=3;
pos--;
while(pos!=1){
ptr=ptr->next;
pos--;
}
middleNode->next=ptr->next;
ptr->next=middleNode;


node*lastNode=NULL;
lastNode=(node*)malloc(sizeof(node));
lastNode->data=3;
lastNode->next=NULL;
current->next=lastNode;



while(head!=NULL){
printf("%d\n",head->data);
head=head->next;
}

}