#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100];
    int i;

    printf("\n\nCopy one string into another string :\n");
    printf("-----------------------------------------\n");
    printf("Input the string : ");
    fgets(str1, sizeof str1, stdin);

    i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }

    str2[i] = '\0';

    printf("\nThe First string is : %s\n", str1);
    printf("The Second string is : %s\n", str2);
    printf("Number of characters copied : %d\n\n", i);

    return 0;
}