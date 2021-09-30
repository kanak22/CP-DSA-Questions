'''
Problem url:
https://leetcode.com/problems/container-with-most-water/
'''


# Solution
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height)-1

        maximum = 0
        
        while i < j:
            if height[i] < height[j]:
                maximum = max(maximum, (j-i) * height[i])
                i += 1
            else:
                maximum = max(maximum, (j-i) * height[j])
                j -= 1

        return maximum
        