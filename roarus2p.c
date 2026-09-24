#include <stdio.h>

// Core Two-Pointer Reverse helper function
void reverse(int arr[], int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotate(int arr[], int size, int k) {
    // Handle cases where k is greater than the array size
    k = k % size; 
    if (k == 0) return;

    // Step 1: Reverse the entire array
    reverse(arr, 0, size - 1);

    // Step 2: Reverse the first 'k' elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse the remaining elements
    reverse(arr, k, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Shift right by 3 spaces

    rotate(arr, size, k);

    printf("Rotated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Output: 5 6 7 1 2 3 4
    }
    return 0;
}
