#include <stdio.h>

void sortArrayByParity(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        // Increment left pointer if it already points to an even number
        if (arr[left] % 2 == 0) {
            left++;
        }
        // Decrement right pointer if it already points to an odd number
        else if (arr[right] % 2 != 0) {
            right--;
        }
        // Swap when left is odd and right is even
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {3, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortArrayByParity(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Output: 4 2 1 3 (or any valid variation)
    }
    return 0;
}
