/* 
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the 
most water.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
the max area of water (blue section) the container can contain is 49.


Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/



class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        // l is the initial leftmost height
        // r is the initial leftmost height
        int l = 0 , r = height.length -1;
        // diff is the distance between two end l and r
        int diff = r-l;
        // looping until l is less than r
        while(l<r){
            diff = r-l;
            int smallestHeight;
            // storing the next smallest height
            if(height[l]> height[r]){
                smallestHeight = height[r];
                r--;
            }else{
                smallestHeight = height[l];
                l++;
            }
            // finding the required area
            int area = smallestHeight * diff;
            // checking for the max area
            if(maxArea<area)
                maxArea = area;
        }
        // System.out.println(maxArea);
        // return the maxArea for the vessel
        return maxArea;
    }
}