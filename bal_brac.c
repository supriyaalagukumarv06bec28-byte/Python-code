/**
 * Challenge: Balanced Brackets (HackerRank)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* isBalanced(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    char* result = "NO";

    for (int i = 0; i < len; i++) {
        char current = s[i];

        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        else if (current == ')' || current == '}' || current == ']') {
            if (top == -1) {
                free(stack);
                return "NO";
            }

            char open = stack[top--];
            if ((current == ')' && open != '(') ||
                (current == '}' && open != '{') ||
                (current == ']' && open != '[')) {
                free(stack);
                return "NO";
            }
        }
    }

    result = (top == -1) ? "YES" : "NO";
    free(stack);
    return result;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    char s[1005];
    while (t--) {
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}
