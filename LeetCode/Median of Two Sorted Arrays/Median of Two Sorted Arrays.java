// Question : https://leetcode.com/problems/median-of-two-sorted-arrays/

// Example :
/**
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */

// Soluution : 

import java.util.*;

class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int num1 = nums1.length, num2 = nums2.length;
        int[] ans = new int[num1 + num2];
        int i=0, j=0, k=0;

        // Insert elements in new array, until one or both of them reaches to last index.

        while(i<num1 && j<num2) {
            if(nums1[i] <= nums2[j])
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        } 

        // If nums2 reaches to last index.

        while(i < num1) {
            ans[k++] = nums1[i++];
        }

        // If num1 reaches to last index.

        while(j < num2) {
            ans[k++] = nums2[j++];
        }
        
        // Find out the median of sorted array by clarifying even/odd length.

        if((num1 + num2)%2 == 0)
            return (double)(ans[ans.length/2-1] + ans[ans.length/2])/2; 
        
        return ans[ans.length/2];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        int[] nums1 = new int[n1];

        for(int i=0; i<n1; i++)
            nums1[i] = sc.nextInt();
        
        int n2 = sc.nextInt();
        int[] nums2 = new int[n2];

        for(int i=0; i <n2; i++)
            nums2[i] = new int[n2];

        System.out.println( findMedianSortedArrays(nums1, nums2) );

        sc.close();
    }
}

// Time complexity : O(m + n)
// Space complexity : O(1)
