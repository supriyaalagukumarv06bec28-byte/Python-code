/**
 * Challenge: Maximum Element (HackerRank)
 * Time Complexity: O(1) per query
 * Space Complexity: O(N)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int data_stack[MAX_SIZE];
int max_stack[MAX_SIZE];
int top = -1;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            top++;
            data_stack[top] = x;
            if (top == 0) {
                max_stack[top] = x;
            } else {
                max_stack[top] = (x > max_stack[top - 1]) ? x : max_stack[top - 1];
            }
        } 
        else if (type == 2) {
            if (top >= 0) top--;
        } 
        else if (type == 3) {
            if (top >= 0) {
                printf("%d\n", max_stack[top]);
            }
        }
    }
    return 0;
}
