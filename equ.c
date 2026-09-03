/**
 * Challenge: Equal Stacks (HackerRank)
 * Strategy: Greedy Three-Pointer Height Reduction
 * Time Complexity: O(N1 + N2 + N3)
 * Space Complexity: O(1) auxiliary
 */

#include <stdio.h>
#include <stdlib.h>

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    long long sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < h1_count; i++) sum1 += h1[i];
    for (int i = 0; i < h2_count; i++) sum2 += h2[i];
    for (int i = 0; i < h3_count; i++) sum3 += h3[i];

    int i = 0, j = 0, k = 0;

    while (i < h1_count && j < h2_count && k < h3_count) {
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i++];
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[j++];
        }
        else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[k++];
        }
    }

    return 0;
}

int main() {
    int n1, n2, n3;
    if (scanf("%d %d %d", &n1, &n2, &n3) != 3) return 0;

    int* h1 = (int*)malloc(n1 * sizeof(int));
    int* h2 = (int*)malloc(n2 * sizeof(int));
    int* h3 = (int*)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) scanf("%d", &h1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &h2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &h3[i]);

    printf("%d\n", equalStacks(n1, h1, n2, h2, n3, h3));

    free(h1);
    free(h2);
    free(h3);
    return 0;
}
