/**
 * Challenge: Truck Tour / Circular Tour (HackerRank)
 * Strategy: Greedy Greedy Window Cycle Identification
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int start_position = 0;
    long long current_petrol = 0;

    for (int i = 0; i < n; i++) {
        long long petrol, distance;
        scanf("%lld %lld", &petrol, &distance);

        current_petrol += (petrol - distance);

        if (current_petrol < 0) {
            start_position = i + 1;
            current_petrol = 0;
        }
    }

    printf("%d\n", start_position);
    return 0;
}
