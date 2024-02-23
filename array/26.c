#include <stdio.h>
struct student{
int id;
float cgpa;
struct student *ptr;
}s1,s2;
int main(){
s1.id=101;
s1.cgpa=4.00;
s1.ptr=NULL;
s1.ptr=&s2;

s2.id=102;
s2.cgpa=3.5;



printf("%d %f",s1.ptr->id,s1.ptr->cgpa);
return 0;

}