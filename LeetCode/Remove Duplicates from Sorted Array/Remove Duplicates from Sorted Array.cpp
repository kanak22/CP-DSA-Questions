class Solution {
    public int removeDuplicates(int[] nums) {
       int n=nums.length;    
        int k=n;
        if(n==0)
            return 0;      //for array with no elements
        
       for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[i+1])    //comparing current element with next element
            {  
                for(int j=i;j<n;j++)   //loop to remove the duplicate number and reorder the array
                {
                   nums[j]=nums[j+1];     
                }
                k--;
                i--;
            }  
        }
        return k;  
    }
}
