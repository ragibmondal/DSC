#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100

int main() {
    char str[str_size];
    int i, wrd; 
    printf("\n\nCount the total number of words in a string :\n"); 
    printf("------------------------------------------------------\n");
    printf("Input the string : ");
    fgets(str, sizeof str, stdin);
    i = 0;
    wrd = 1;
    /* Loop to count words in the string */
    while (str[i] != '\0') { 
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            wrd++;
        }

        i++;
    }
    printf("Total number of words in the string is : %d\n", wrd - 1); 
	return 0;
}