/**
 * Challenge: Waiter (HackerRank)
 * Strategy: Stack Sorting using Pre-generated Prime Divisors
 * Time Complexity: O(Q * N)
 * Space Complexity: O(N + Q)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLATES 50005
#define MAX_PRIMES 1205

int primes[MAX_PRIMES];
int stackA[MAX_PLATES];
int nextA[MAX_PLATES];
int stackB[MAX_PLATES];

// Generate first Q prime numbers efficiently
void generatePrimes(int q) {
    int count = 0;
    int num = 2;
    while (count < q) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
        num++;
    }
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    generatePrimes(q);

    int topA = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &stackA[topA++]);
    }

    for (int i = 0; i < q; i++) {
        int currentPrime = primes[i];
        int topNextA = 0;
        int topB = 0;

        while (topA > 0) {
            int plate = stackA[--topA];
            if (plate % currentPrime == 0) {
                stackB[topB++] = plate;
            } else {
                nextA[topNextA++] = plate;
            }
        }

        while (topB > 0) {
            printf("%d\n", stackB[--topB]);
        }

        for (int j = 0; j < topNextA; j++) {
            stackA[j] = nextA[j];
        }
        topA = topNextA;
        
        if (topA == 0) break;
    }

    while (topA > 0) {
        printf("%d\n", stackA[--topA]);
    }

    return 0;
}
