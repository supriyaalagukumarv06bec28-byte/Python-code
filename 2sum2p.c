#include <stdio.h>

void findTwoSum(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == target) {
            printf("Found numbers: %d and %d\n", arr[left], arr[right]);
            return;
        } else if (current_sum < target) {
            left++;  // Need a larger sum
        } else {
            right--; // Need a smaller sum
        }
    }
    printf("No pair found.\n");
}

int main() {
    int arr[] = {2, 7, 11, 15}; // Array must be sorted
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);

    findTwoSum(arr, size, target); // Output: Found numbers: 2 and 7
    return 0;
}
