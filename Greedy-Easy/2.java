// Program to find minimum number of barbers required
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
import java.util.Scanner ;
import java.util.Arrays ;

class Main {
    
    // Returns minimum number of barbers required
    static int numberOfBarbersRequired(int arr[], int dep[], int n)
    {
    	// Sort arrival and departure arrays
    	Arrays.sort(arr);
    	Arrays.sort(dep);
    
    	// barb_needed indicates number of barbers
    	// needed at a time
    	int barb_needed = 1, result = 1;
    	int i = 1, j = 0;
    
    	// Similar to merge in merge sort to process
    	// all events in sorted order
    	while (i < n && j < n) {
    		// If next event in sorted order is arrival,
    		// increment count of barbers needed
    		if (arr[i] <= dep[j]) {
    			barb_needed++;
    			i++;
    		}
    
    		// Else decrement count of barbers needed
    		else if (arr[i] > dep[j]) {
    			barb_needed--;
    			j++;
    		}
    
    		// Update result if needed
    		if (barb_needed > result)
    			result = barb_needed;
    	}
    
    	return result;
    }
    
    public static void main(String a[]) {
        
        Scanner sc = new Scanner(System.in) ;
        
        int n = sc.nextInt() ;
        
        int arr[] = new int[n] ;
        
        for(int i = 0 ; i<n ; i++)
            arr[i] = sc.nextInt() ;
        
        int dep[] = new int[n] ;
        
        for(int i = 0 ; i<n ; i++)
            dep[i] = sc.nextInt() ;
            
        System.out.println( numberOfBarbersRequired(arr, dep, n) ) ;
    }
}