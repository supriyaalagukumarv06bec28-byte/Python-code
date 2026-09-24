#include <stdio.h>

void moveZeroes(int arr[], int size) {
    int insert_pos = 0;

    // Step 1: Shift all non-zero elements forward
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[insert_pos] = arr[i];
            insert_pos++;
        }
    }

    // Step 2: Fill the remaining space with zeroes
    while (insert_pos < size) {
        arr[insert_pos] = 0;
        insert_pos++;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Output: 1 3 12 0 0
    }
    return 0;
}
