#include <stdio.h>

struct student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    struct student number[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter the %d student information:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &number[i].id);
        printf("Enter name: ");
        scanf(" %[^\n]", number[i].name);  // Read a line of text with spaces
        printf("Enter CGPA: ");
        scanf("%f", &number[i].cgpa);
    }

    printf("\nID\tName\tCGPA\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%s\t%.2f\n", number[i].id, number[i].name, number[i].cgpa);
    }

    return 0;
}
