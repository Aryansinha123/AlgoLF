/*Problem Statement

You are a savvy thief preparing to rob a jewelry store. You have a knapsack with a limited capacity and a list of items, each with a certain weight and a corresponding profit.

Your objective is to maximize the total profit you can obtain by selecting items to place in your knapsack while staying within its weight capacity. Write a program to help you calculate the maximum profit you can achieve.

Note: Use the 0/1 knapsack method to solve the program.
Example

Input:
3
60 10
100 20
120 30
50

Output:
220

Explanation:

By selecting the second and third items, you achieve a maximum profit of Rs. 220. The sum of their profits (100 + 120) gives you the highest total profit while not exceeding the knapsack's weight capacity of 50.

Input format :
The first line contains an integer N, representing the number of items available in the store.

Each of the next N lines contains two space-separated integers P and W, where P is the profit that can be obtained by stealing the item and W is the weight of the item.

The last line contains an integer C representing the weight capacity of your knapsack.

Output format :
The output displays the maximum total profit that you can achieve by selecting items for your knapsack.

Refer to the sample output for the formatting specifications

Code constraints :
1 ≤ N ≤ 10

1 ≤ P, W ≤ 200

1 ≤ C ≤ 50

Sample test cases :
Input 1 :
3
60 10
100 20
120 30
50
Output 1 :
220
Input 2 :
2
10 30
20 60
70
Output 2 :
20*/
#include <stdio.h>
int knapsack(int N, int W, int profits[], int weights[])
{
    int dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = (profits[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) ? profits[i - 1] + dp[i - 1][j - weights[i - 1]] : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][W];
}
int main()
{
    int N, W;
    scanf("%d", &N);
    int profits[N], weights[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &profits[i], &weights[i]);
    }
    scanf("%d", &W);
    int maxProfit = knapsack(N, W, profits, weights);
    printf("%d\n", maxProfit);
    return 0;
}