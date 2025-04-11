#include <stdio.h>
#include <stdlib.h>
int maxSubarraySum(int arr[], int n)
{
    int x = arr[0], y = arr[0];
    for (int i = 1; i < n; i++)
    {
        y = (arr[i] > y + arr[i]) ? arr[i] : y + arr[i];
        x = (x > y) ? x : y;
    }
    return x;
}
int main()
{
    int N;
    scanf("%d", &N);
    int A[N], B[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }
    int maxSumA = maxSubarraySum(A, N);
    int maxSumB = maxSubarraySum(B, N);
    printf("%d\n", maxSumA);
    printf("%d\n", maxSumB);
    printf("%d\n", maxSumA + maxSumB);
    return 0;
}