/**
 * Challenge: Queue using Two Stacks (HackerRank)
 * Time Complexity: O(1) Amortized per operation
 * Space Complexity: O(N)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }
int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    
    while (q--) {
        int type;
        scanf("%d", &type);
        
        if (type == 1) {
            int x;
            scanf("%d", &x);
            push1(x);
        } else {
            if (top2 == -1) {
                while (top1 != -1) {
                    push2(pop1());
                }
            }
            if (type == 2) {
                pop2();
            } else if (type == 3) {
                printf("%d\n", stack2[top2]);
            }
        }
    }
    return 0;
}
