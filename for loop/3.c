#include <stdio.h>
2	int main(){
3	    int num,r,sum=0,temp;
4	    printf("Input  a number: \n");
5	    num = 153;
6	    for(temp=num;num!=0;num=num/10){
7	         r=num % 10;
8	         sum=sum+(r*r*r);
9	    }
10	    if(sum==temp)
11	         printf("%d is an Armstrong number.\n",temp);
12	    else
13	         printf("%d is not an Armstrong number.\n",temp);
return 0;
14	}