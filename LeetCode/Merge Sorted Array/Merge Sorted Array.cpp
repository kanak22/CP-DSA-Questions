class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //take an array of size m+n to merge the two sorted arrays
        int arr[m+n];
        int i=0,j=0,k=0;
        //loop over both the arrays and check for the smaller elements simultaneously
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                arr[k++]=nums1[i++]; //insert the smaller number into the array arr
            else
                arr[k++]=nums2[j++];
        while(i<m) //copy any leftover elements
            arr[k++]=nums1[i++];
        while(j<n) //copy any leftover elements
            arr[k++]=nums2[j++];
        for(k=0;k<(m+n);k++) //copy the arr array elements into nums1
            nums1[k]=arr[k];
        return;
    }
};
