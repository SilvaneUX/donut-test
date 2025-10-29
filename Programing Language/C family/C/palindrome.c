#include <stdbool.h>
//to check if the given number is a palindrome number or not
bool isPalindrome(int x) {
    if (x < 0) return false;  // negative numbers are not palindromes

    long reversed = 0;
    int original = x;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return (reversed == original);
}