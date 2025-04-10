/*Anu has a collection of unique, non-negative integers, and she needs to count how many subsets of those integers sum up to a specific target number, K. She wants to identify all possible ways to choose the subsets of elements from the collection such that their total sum equals K. The challenge involves using the elements of the set without any repetition and ensuring that the target sum is achieved.

Input format :
The first line of input contains the integer n , representing the number of elements in the array.

The next line contains n space-separated integers, which represent the elements of the array.

The final input is the integer K , which is the target sum.

Output format :
The output prints a single integer, which represents the count of subsets whose sum is equal to the target sum K.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 1000

0 ≤ array[i] ≤ 1000

1 ≤ K ≤ 1000

Sample test cases :
Input 1 :
4
1 3 5 2
6
Output 1 :
2
Input 2 :
8
15 22 14 26 32 9 16 8
53
Output 2 :
3
*/
#include <stdio.h>

int countSubsets(int arr[], int n, int K, int index)
{
    if (K == 0)
        return 1;
    if (index == n || K < 0)
        return 0;

    return countSubsets(arr, n, K - arr[index], index + 1) + countSubsets(arr, n, K, index + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int K;
    scanf("%d", &K);

    printf("%d\n", countSubsets(arr, n, K, 0));

    return 0;
}
