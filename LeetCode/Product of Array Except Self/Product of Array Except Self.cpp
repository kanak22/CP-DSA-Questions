/* Question Link- https://leetcode.com/problems/product-of-array-except-self/
*/

// Given an integer array nums, 
// return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 /*Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/

/*Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
 */

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 
 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        
     int n=a.size();
     vector<int> ds;
        ds.push_back(1);
        for(int i=1;i<n;i++)  ds.push_back(ds[i-1]*a[i-1]);
        
      int r=1;
        
        for(int i=n-1;i>=0;i--)  ds[i]=ds[i]*r, r=a[i]*r;
        
        return ds ;
    }
    
};