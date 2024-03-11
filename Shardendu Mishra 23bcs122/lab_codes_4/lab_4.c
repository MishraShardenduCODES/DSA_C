// 4.Write a program to search for an element using the
// linear search approach. The program should be able
// to allocate the memory for the required number of
// elements dynamically when the program is under
// execution. Use the suitable dynamic memory
// allocation functions
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Dynamically allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    int index = linearSearch(arr, n, key);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }
    // Free dynamically allocated memory
    free(arr);
    return 0;
}
