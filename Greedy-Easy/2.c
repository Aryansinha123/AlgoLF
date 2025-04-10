/*Problem Statement



You are given the time at which customers enter a barbershop and leave after the service. You need to find the minimum number of barbers required so that no customer waits for the service but is served instantly. 



Use greedy algorithm to solve the given problem.



Example:

Input:

5

1 2 3 4 5

2 3 4 6 7

Output:

2

Explanation:

All men arriving at times 1, 3, and 5 can be served by Barber 1. Here, Barber 2 serves all men who enter the shop at times 2 and 4, so another barber is needed. Therefore, a total of two people is required.

Input format :
The first line of input is an integer value representing the total number of customers n.

The second line is space-separated integer values representing the arrival time.

The third line is space-separated integer values representing the leaving time.

Output format :
The output prints the number of barbers required.



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ n ≤ 5

1 ≤ arrival time & leaving time ≤ 10

Sample test cases :
Input 1 :
5
1 2 3 4 5
2 3 4 6 7
Output 1 :
2
Input 2 :
2
1 3
2 4
Output 2 :
1*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=1;
    int j=0;
    int max=1;
    int b=1;
    int n;
    scanf("%d",&n);
    int a[n],d[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++){
        scanf("%d",&d[j]);
    }
    while(i<n && j<n){
        if(a[i]<=d[j]){
            b=b+1;
            i=i+1;
        }else{
            b=b-1;
            j=j+1;
        }
    }
    printf("%d",b);
}