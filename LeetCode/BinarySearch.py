#Question Link : https://leetcode.com/problems/binary-search/
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        while left < right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            if nums[mid] > target:
                right = mid -1
        if nums[left] == target:
            return left
        return -1
