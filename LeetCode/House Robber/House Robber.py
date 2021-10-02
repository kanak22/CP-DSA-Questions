"""This is a pretty simple problem. The constraints are fairly small so even naive approach is efficient.
We will just keep adding the alternate elements of that list. So there will be two variables, one is the sum of odd indexed numbers and
another is the sum of even indexed numbers. Finally to get maximum amount of money without alerting police
we will just print the maximum of the two values. That will be our expected output."""

class Solution :
    def rob(self, nums: list[int]) -> int :
        even=0; odd=0   # initialize the variables
        for i in range(len(nums)) :
            if i % 2 == 0:
                even += nums[i] # keep adding even indexed elements
            else:
                odd += nums[i]  # keep adding odd indexed elements
        return max(even,odd)    # return the maximum of the two

# Time Complexity : O(n)