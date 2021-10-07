import java.util.*;
public class House_robbery {
	static int t[];  // Declaring a global array to store the maximum value returned by a recursive call from a sub-array.
    public static int calculate(int arr[], int n) {
    	if(n<1)
    		return 0;
    	//If the maximum value from a sub-array has already been calculated, we'll fetch it from the t[] array.
    	if(t[n]!=-1)
    		return t[n];
    	// If the maximum value from a sub-array has not been calculated yet, we'll call the recursive function and store the max value in the t[] array.
    	return t[n]= Math.max((arr[n-1]+ calculate(arr,n-2)),(calculate(arr,n-1)));
    	
    }
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n= sc.nextInt();
		t= new int[n+1];
		for(int i=1; i<=n; i++)
			t[i]=-1;
		int arr[]= new int[n];
		for(int i=0; i<n; i++)
			arr[i]= sc.nextInt();
		int ans= calculate(arr,n);
		System.out.println(ans);
		sc.close();
	}
}
/* In the Leetcode problem statement, the function definition is different.
 *  We can simply make a function call from the given function definition to the above function definition
 *  class Solution {
     int t[];
    public int rob(int[] nums) {
        t= new int[nums.length+1];
        for(int i=1; i<=nums.length; i++)
            t[i]=-1;
        return robHouse(nums, nums.length);
    }
    public int robHouse(int[] nums, int n) {
        if(n<1)
    		return 0;
    	if(t[n]!=-1)
    		return t[n];
    	return t[n]= Math.max((nums[n-1]+ robHouse(nums,n-2)),(robHouse(nums,n-1)));
    	
    }
    
}*/
 