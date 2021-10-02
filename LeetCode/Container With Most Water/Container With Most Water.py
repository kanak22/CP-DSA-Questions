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
                # if maxuimum is smaller than current container
                # Assign maximum to the the higher value 
                maximum = max(maximum, (j-i) * height[i])
                i += 1 # Increase index
            else:
                # if maxuimum is smaller than current container
                # Assign maximum to the the higher value 
                maximum = max(maximum, (j-i) * height[j])
                j -= 1 # Decrease index

        return maximum
