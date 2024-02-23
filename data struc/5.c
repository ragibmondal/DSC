#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int p;
    char q[50];
    float r;
    struct node *next;
};
int main(){
    typedef struct node node;
    node* a= malloc(sizeof(node));
    node* b= malloc(sizeof(node));
    node* c= malloc(sizeof(node));
    node* d= malloc(sizeof(node));
    node* e= malloc(sizeof(node));
    a->p=3;
    strcpy(a->q,"Pom");
    a->r=3.2;
    a->next=b;

    b->p=4;
    strcpy(b->q,"Rom");
    b->r=4.2;
    b->next=c;

    c->p=5;
    strcpy(c->q,"Dom");
    c->r=5.2;
    c->next=d;

    d->p=6;
    strcpy(d->q,"Lom");
    d->r=6.2;
    d->next=e;

    e->p=7;
    strcpy(e->q,"Mom");
    e->r=3.54;
    e->next=NULL;

    node* ragib = malloc(sizeof(node));
    ragib->p = 8;
    strcpy(ragib->q, "Ragib");
    ragib->r = 3.54;
    ragib->next =a;
    a=ragib;
    
  
   /*node* ptr=a;
   while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ragib;  //insert from last

    node* ptr=a;
    int pos=5;
    while(pos==2){
        ptr=ptr->next;
    }

    node* delf;//first dellet
    delf=a;
    a=a->next;
    free(delf);
    
   node* delm1;//middle delate
    node* delm2;
    int pos=5;
    delm1=a;
    delm2=a;
    while(pos!=4){
    delm1=delm2;
    delm1=delm1->next;
    pos--;
    }
   delm2->next=delm1->next;
   free(delm1);
   delm1=NULL;

   node* dell1;
   node* dell2;
   dell1=a;
   dell2=a;
   while(dell2!=NULL){
    dell1=dell2;
    dell2= dell2->next;
   }
   free(dell2);
   dell2=NULL;*/

    node*ptr=a;
    while(ptr!=NULL){
        printf("%d %s %f\n",ptr->p, ptr->q,ptr->r);
        ptr=ptr->next;
    }

node* list=a;
int cur=0;
while(list!=NULL){
    cur++;
    list=list->next;
}
node* cse=a;
int ser=0;
while(cse!=NULL){
    if(cse->p==3){
        ser++;
        cse=cse->next;
    }
    cse=cse->next;

}
if(ser==0){
    printf("Data Not found\n");
}
else{
    printf(" Data Repeted %d ",ser);
}


printf("Total Node %d",cur);
   return 0;
}