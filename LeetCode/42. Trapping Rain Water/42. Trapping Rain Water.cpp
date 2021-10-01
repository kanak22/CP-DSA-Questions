/*
Question : 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
Link : https://leetcode.com/problems/trapping-rain-water/
*/

// Code : 

#include<algorithm>
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        for( int i = 0; i < height.size(); i ++ )
        {
            int h = height[i];
            if ( h != 0 )
            {
                if ( (i + 1) < height.size() && height[ i + 1 ] >= h )
                    continue;
                int end = 0;
                int flag = 0;
                int max = 0;
                for ( int j = i + 2; j < height.size(); j ++ )
                {
                    if ( height[j] >= h )
                    {
                        end = j;
                        max = height[j];
                        flag = 2;
                        break;
                    }
                    if ( height[j] > max )
                    {
                        end = j;
                        max = height[j];
                        flag = 1;
                    }
                }

                if ( flag == 0 )
                    continue;
                int effh = min( h, max);
                for( int k = i + 1; k < end; k ++ )
                {
                    if ( effh <= height[k] )
                        continue;
                    water += (effh - height[k]);
                }
                i = end - 1;
            }
        }
        return water;
    }
};
