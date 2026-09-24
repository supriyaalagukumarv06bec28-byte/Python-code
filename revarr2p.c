#include <stdio.h>

void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        // Swap elements at left and right pointers
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers closer to the center
        left++;
        right--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Output: 5 4 3 2 1
    }
    return 0;
}
