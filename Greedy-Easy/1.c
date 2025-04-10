/*Problem Statement

Given an infinite supply of each denomination of Indian currency {1, 2, 5, 10, 20, 50, 100, 500, 1000} and a target value N. Find the minimum number of coins and/or notes needed to make the change for Rs. N, using a greedy algorithm. 
You must return the list containing the required value of the coins. 

Example
Input: 

43

Output: 

20 20 2 1

Input format :
The input consists of a single integer N, representing the amount for which the minimum denominations need to be found.

Output format :
The output consists of a single line containing the denominations required to represent the given amount, separated by spaces.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 106

Sample test cases :
Input 1 :
43
Output 1 :
20 20 2 1 
Input 2 :
1000
Output 2 :
1000 
Input 3 :
958
Output 3 :
500 100 100 100 100 50 5 2 1 */

#include <stdio.h>

int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V) {
    // Traverse through all denominations
    for (int i = n - 1; i >= 0; i--) {
        // Find the maximum number of current denomination
        while (V >= deno[i]) {
            V -= deno[i];
            printf("%d ", deno[i]);
        }
    }
}

int main() {
    int value;
    scanf("%d", &value);

    findMin(value);

    return 0;
}