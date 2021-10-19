class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #removing all the duplicates at once using set()
        nums[:] = list(set(nums))
        #sorting the array nums
        nums.sort()
        return len(nums)
        