#include <stdio.h>

int main() {
    int arr1[100], arr2[100], arr3[200];
    int size1, size2, size3;
    int i, j, k;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter the elements of the first array in descending order: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter the elements of the second array in descending order: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge the two arrays into a third array
    size3 = size1 + size2;
    for (i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for (j = 0; j < size2; j++) {
        arr3[i] = arr2[j];
        i++;
    }

    // Sort the merged array in descending order
    for (i = 0; i < size3; i++) {
        for (k = 0; k < size3 - 1; k++) {
            if (arr3[k] <= arr3[k + 1]) {
                int temp = arr3[k + 1];
                arr3[k + 1] = arr3[k];
                arr3[k] = temp;
            }
        }
    }

    // Print the merged array
    printf("The merged array in descending order is: ");
    for (i = 0; i < size3; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
