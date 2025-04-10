/*Problem Statement



Ragul is interested in solving the knapsack problem. He has a list of n items, each with a weight and a value. 



Ragul wants to determine the maximum value he can obtain by selecting a combination of items to fit into his knapsack, which has a maximum weight capacity.



Help Ragul write a program that calculates the following:



Calculate and print the sum of all n values.
Calculate and print the average value of all n values with exactly 2 decimal places.
Calculate and print the maximum value that can be obtained by selecting a combination of items to fit into the knapsack without exceeding its capacity.


Note: Use the 0/1 knapsack method to solve the problem.

Input format :
The first line contains an integer n, the number of items.

The next line contains n space-separated integers, the weights of the items.

The next line contains n space-separated integers, the values of the items.

The last line contains an integer C, the maximum weight capacity of the knapsack.

Output format :
The output consists of the following in each line:

The sum of all n values as an integer.
The average value of all n values with exactly 2 decimal places is a double value.
The maximum value that can be obtained as an integer.


Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ Weight of each item ≤ 100

1 ≤ Value of each item ≤ 100

1 ≤ C ≤ 30

Sample test cases :
Input 1 :
3
10 15 20
45 65 70
30
Output 1 :
Sum of values: 180
Average of values: 60.00
Maximum amount: 115
Input 2 :
4
3 4 5 6
8 10 12 15
12
Output 2 :
Sum of values: 45
Average of values: 11.25
Maximum amount: 30*/
#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack(int C,int weights[],int values[],int n){
    int dp[n+1][C+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=C;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }else if(weights[i-1]<=w){
                dp[i][w]=max(values[i-1]+dp[i-1] [w-weights[i-1]],dp[i-1][w]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
            }
        }
        return dp[n][C];
    }
int main(){
    int n;
    scanf("%d",&n);
    int weights[n],values[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
    int C;
    scanf("%d",&C);
    int sumValues=0;
    for(int i=0;i<n;i++){
        sumValues+=values[i];
    }
    double avgValue=(double)sumValues/n;
    int maxValue=knapsack(C,weights,values,n);
    printf("Sum of values: %d\n",sumValues);
    printf("Average of values: %.2f\n",avgValue);
    printf("Maximum amount:%d\n",maxValue);
    return 0;
    
}    