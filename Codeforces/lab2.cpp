// Creator:  Anudeep Sanapala
// Date: 23/09/2023
// Description: This program is to find the modular inverse of a number using extended euclidean algorithm.
// Functions: gcdExtended, modInverse
// Input: a, m
// Output: Modular multiplicative inverse of a under modulo m

#include <stdio.h>


int gcdExtended(int a, int b, int *x, int *y);

// Function to find modular inverse of 'a' under modulo 'm'
// Assumption: 'm' is prime
void modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);

    if (gcd != 1) {
        printf("Inverse doesn't exist\n");
    } else {
        // Ensure that the result is positive
        int result = (x % m + m) % m;
        printf("Modular multiplicative inverse is %d\n", result);
    }
}

// Extended Euclidean algorithm to find gcd(a, b) and coefficients x, y
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, m;
    // printf("Enter the number and modulo: ");
    scanf("%d %d", &a, &m);
    modInverse(a, m);
    return 0;
}