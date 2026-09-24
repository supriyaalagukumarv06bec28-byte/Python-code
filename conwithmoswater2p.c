#include <stdio.h>

int maxArea(int height[], int size) {
    int left = 0;
    int right = size - 1;
    int max_water = 0;

    while (left < right) {
        // Find the limiting height between the two lines
        int current_height = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int current_water = current_height * width;

        // Update maximum water found so far
        if (current_water > max_water) {
            max_water = current_water;
        }

        // Move the pointer that has the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_water;
}

int main() {
    int heights[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(heights) / sizeof(heights[0]);

    printf("Max water container can hold: %d\n", maxArea(heights, size)); // Output: 49
    return 0;
}
