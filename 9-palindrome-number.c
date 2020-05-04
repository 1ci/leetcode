#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

/**
 * Determine whether an integer is a palindrome. 
 * An integer is a palindrome when it reads the same backward as forward.
 */
int main(int argc, char** argv) {
    isPalindrome(121);
    isPalindrome(123321);
    isPalindrome(10);
    return 0;
}

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int revertedNumber = 0;
    while ( x > revertedNumber ) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}
