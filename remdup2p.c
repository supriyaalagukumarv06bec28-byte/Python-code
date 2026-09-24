#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;

    int write = 1; // Points to where the next unique element should go

    for (int read = 1; read < size; read++) {
        // If we find a new unique element
        if (arr[read] != arr[read - 1]) {
            arr[write] = arr[read];
            write++;
        }
    }
    return write; // Returns the new length of the unique array
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int new_length = removeDuplicates(arr, size);

    printf("New length: %d\nElements: ", new_length);
    for (int i = 0; i < new_length; i++) {
        printf("%d ", arr[i]); // Output: 1 2 3 4
    }
    return 0;
}
