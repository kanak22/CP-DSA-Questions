class Solution {
public void merge(int[] nums1, int m, int[] nums2, int n) {

    //3 pointers {i for nums1 , j for nums2, k for output array}
    int i = 0 , j = 0 , k = 0;
    int[] output = new int[m+n];
    
    //run the loop till both the pointers meet the given size of array
    while(i < m && j < n){
        if(nums1[i]<=nums2[j]){
            output[k] = nums1[i];
            i++;
        }else{
            output[k] = nums2[j];
            j++;
        }
        k++;
    }
    
    //if i didn't meet end put all remaining elements of nums1 
    while(i < m){
        output[k]= nums1[i];
        i++;
        k++;
    }
    //if j didn't meet end put all remaining elements of nums2
    while(j < n){
        output[k]= nums2[j];
        j++;
        k++;
    }
    
    //updating values of nums1 array with output array's values 
    for(int idx = 0; idx < nums1.length; idx++){
        nums1[idx] = output[idx];
    }
}
}
