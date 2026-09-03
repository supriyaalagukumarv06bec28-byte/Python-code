/**
 * Challenge: AND XOR OR (HackerRank)
 * Strategy: Simplified Bitwise Reduction via Monotonic Increasing Stack
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    int max_xor = 0;

    for (int i = 0; i < n; i++) {
        int current;
        scanf("%d", &current);

        // Evaluate with elements larger than the current item
        while (top >= 0 && stack[top] > current) {
            int prev = stack[top--];
            int current_xor = prev ^ current;
            if (current_xor > max_xor) {
                max_xor = current_xor;
            }
        }

        // Pair with the nearest smaller element to its left
        if (top >= 0) {
            int current_xor = stack[top] ^ current;
            if (current_xor > max_xor) {
                max_xor = current_xor;
            }
        }

        stack[++top] = current;
    }

    printf("%d\n", max_xor);
    free(stack);
    return 0;
}
