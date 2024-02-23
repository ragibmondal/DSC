#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    struct Student students[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter student %d's information:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %s", students[i].name);  // Read a line of text with spaces

        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);
    }

    printf("\nID\t\tName\t\tCGPA\n"); // Table header
    for (int i = 0; i < 3; i++) {
        printf("%d\t\t%s\t\t%f\n", students[i].id, students[i].name, students[i].cgpa); // Corrected format specifiers
    }

    return 0;
}


