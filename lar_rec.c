/**
 * Challenge: Largest Rectangle in a Histogram (HackerRank)
 * Strategy: Monotonic Increasing Stack
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <stdio.h>
#include <stdlib.h>

long long largestRectangle(int h_count, int* h) {
    int* stack = (int*)malloc((h_count + 1) * sizeof(int));
    int top = -1;
    long long max_area = 0;

    int i = 0;
    while (i <= h_count) {
        int current_height = (i == h_count) ? 0 : h[i];

        if (top == -1 || current_height >= h[stack[top]]) {
            stack[++top] = i;
            i++;
        } else {
            int popped_idx = stack[top--];
            long long height = h[popped_idx];
            long long width = (top == -1) ? i : (i - stack[top] - 1);
            long long current_area = height * width;

            if (current_area > max_area) {
                max_area = current_area;
            }
        }
    }

    free(stack);
    return max_area;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* h = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    printf("%lld\n", largestRectangle(n, h));

    free(h);
    return 0;
}
