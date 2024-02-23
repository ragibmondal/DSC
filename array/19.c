#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    
    printf("The characters of the string in reverse order are: ");
    for (i = len - 1; i >= 0; --i) {
        printf("%c  ", str[i]);
    }

    printf("\n");
    
    return 0;
}
