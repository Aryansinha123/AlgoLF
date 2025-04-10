// Program to find minimum number of barbers required
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