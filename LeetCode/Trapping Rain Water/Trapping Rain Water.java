// Question : https://leetcode.com/problems/trapping-rain-water/

// Example :
/**
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped.
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 */

// Solution

class Solution {
    public static int trap(int[] height) {
        int tot=0;

        for(int i=1;i<height.length-1;i++){
            int m1=0;
            
            // checkout top most height on right side of that building

            for(int j=0;j<=i;j++){
                m1=Math.max(m1,height[j]);
            }

            int m2=0;

            // checkout top most height on left side of that building

            for(int k=i;k<height.length;k++){
                m2=Math.max(m2,height[k]);
            }

            // checkout min height form most right and left side
            // the minimum will collect the at least water.

            tot+=Math.min(m1,m2)-height[i];
        }

        return tot;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] height = new int[n];
        
        for(int i = 0; i < n; i ++) {
            height[i] = sc.nextInt();
        }
        
        System.out.println( height );
    }
}

// Time Complexity : O(n2)
// Space Complexity : O(1)
