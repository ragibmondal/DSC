#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next  };
typedef struct Node node;

int main()
{
    node *head,*fst,*sec,*trd,*frt;
    head=(node*)malloc(sizeof(node));
    fst=(node*)malloc(sizeof(node));
    sec=(node*)malloc(sizeof(node));
    trd=(node*)malloc(sizeof(node));
    frt=(node*)malloc(sizeof(node));
    head->data=1;
    fst->data=2;
    sec->data=3;
    trd->data=4;
    frt->data=5;
    head->next=fst;
    fst->next=sec;
    sec->next=trd;
    trd->next=frt;
    frt->next=NULL;
    //counting

node*list;
list=head;
int cur=0;
while(list!=NULL)
{
    cur++;
    list=list->next;
}
printf("Total node is only %d |\n",cur);
//searching
node*ser;
ser=head;
  int sar=0;
while(ser!=NULL)
{
    if(ser->data == 2)
    {

        sar++;
    }
    ser=ser->next;
}
if(sar == 0)
{
    printf("Data Not Found");
}
else
{
    printf("Data Found and it %d times|\n",sar);
}
//first delete
node*delF;
delF=head;
head=head->next;
free(delF);
//Mid delete
node*delM1;
node*delM2;
int pos=4;
delM1=head;
delM2=head;
while(pos !=3)
{
    delM2=delM1;
    delM1=delM1->next;
    pos--;
}
delM2->next=delM1->next;
free(delM1);
delM1=NULL;

    //last Delete
   node*delL1,*delL2;
   delL1=head;
   delL2=head;
   while(delL2->next!=NULL)
   {
       delL1=delL2;
       delL2=delL2->next;
   }
free(delL2);
delL2=NULL;
delL1->next=NULL;

    //print Calling
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    };
    return 0;
}