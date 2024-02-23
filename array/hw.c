#include <stdio.h>

struct student {
    int id;
    char name[50];
    int cgpa;
};

int main() {
    struct student students[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter the %d student information:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter CGPA: ");
        scanf("%d", &students[i].cg pa);
    }

    printf("\nID\t\tName\t\tCGPA\n"); 
    for (int i = 0; i < 3; i++) {
        printf("%d\t\t%s\t\t%d\n", students[i].id, students[i].name, students[i].cgpa);
    }

    return 0;
}
