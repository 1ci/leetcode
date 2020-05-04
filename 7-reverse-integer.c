#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// int safe_add(int a, int b) {
//     if (a > 0 && b > INT_MAX - a) {
//         /* handle overflow */
//         return 0;
//     } else if (a < 0 && b < INT_MIN - a) {
//         /* handle underflow */
//         return 0;
//     }
//     return a + b;
// }

int main(int argc, char** argv)
{
    printf("sizeof(int) = %d", sizeof(int));

    reverse(12345);
    return 0;
}

// Given a 32-bit signed integer, reverse digits of an integer.
// Assume we are dealing with an environment which could only store integers within the 32-bit
// signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, 
// assume that your function returns 0 when the reversed integer overflows.
int reverse(int x) {
    int remainder;
    int rev = 0;

    while (x != 0) {
        remainder = x % 10;

        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            /* handle overflow and underflow */
            return 0;
        }
        rev = rev * 10;

        if (rev > 0 && remainder > INT_MAX - rev ||
            rev < 0 && remainder < INT_MIN - rev) {
            /* handle overflow and underflow */
            return 0;
        }
        rev += remainder;

        x /= 10;
    }
    return rev;
}
