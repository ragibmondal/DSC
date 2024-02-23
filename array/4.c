#include <stdio.h>
int main(){
    int n;
    printf("enter the elment number that coppied from array1 to array2\n");
    scanf("%d",&n);
    int a[100],b[100];

    for(int i=1;i<=n;i++){
        printf("Enter the element %d\n",i);
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
      b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
      printf("Coppied Number %d\n",b[i]);

    }
    return 0;
}