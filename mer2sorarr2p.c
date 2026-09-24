#include <stdio.h>

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for result array

    // Compare elements from both arrays and insert the smaller one
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[7];

    mergeSortedArrays(arr1, n1, arr2, n2, result);

    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", result[i]); // Output: 1 2 3 4 5 6 7
    }
    return 0;
}
