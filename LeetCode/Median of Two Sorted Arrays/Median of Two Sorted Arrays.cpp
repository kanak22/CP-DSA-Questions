#include <iostream>
#include <vector>
  
using namespace std;
// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Method to find median of two sorted arrays(vectors) 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size();
    int n=nums2.size();
    vector<float> merged;
    int i=0;
    int j=0;
   
    // Add elements in merged vector until one of the two vector get completed
    while(i<m && j<n){
        if(nums1[i]>nums2[j]){
            merged.push_back(nums2[j]) ;
            j++;
        }else{
            merged.push_back(nums1[i]);
            i++;
        }
    }
    // add remaining elements of nums2 if nums1 fully added
    if(j<n){
        while(j<n){
            merged.push_back(nums2[j]);
            j++;
        }
    }
    // add remaining elements of nums1 if nums2 fully added
        if(i<m){
        while(i<m){
            merged.push_back(nums1[i]);
            i++;
        }
    }
    
    
    if((m+n)%2!=0){
        return merged[(m+n-1)/2];
    }else{
        return  (merged[(m+n)/2]+merged[((m+n)/2)-1])/2;
    }
}



int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2);
}