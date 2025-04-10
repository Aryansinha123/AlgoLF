/*Problem Statement
Create a mystical calculator for wizards who excel in base-to-exponent calculations using the divide-and-conquer method. 

Your task is to design this calculator, accepting positive base and exponent values and producing magical results using the mystical technique. 

Input format :
The input consists of two space-separated integers: base and exponent.

Output format :
The output displays the result of the exponentiation calculation in the following format:

[base]^([exponent]) = [result]

Refer to the sample output for the exact format.

Code constraints :
0 <= base, exponent <= 15

Sample test cases :
Input 1 :
3 4
Output 1 :
3 ^ 4 = 81
Input 2 :
10 0
Output 2 :
10 ^ 0 = 1
Input 3 :
0 2
Output 3 :
0 ^ 2 = 0*/
#include <stdio.h>

// Function to calculate power using divide and conquer
long long int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 0) {
        long long int half = power(base, exponent / 2);
        return half * half;
    } 
    else {
        long long int half = power(base, (exponent - 1) / 2);
        return half * half * base;
    }
}

int main() {
    int base, exponent;

    scanf("%d", &base);
    scanf("%d", &exponent);

    long long int result = power(base, exponent);

    printf("%d ^ %d = %lld", base, exponent, result);
    return 0;
}