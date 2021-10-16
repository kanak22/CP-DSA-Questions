class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # Only takes unique triplets since it is a set
        triplet_set = set()

        for i in range(0, len(nums)):
            complements = set()
            for j in range(i + 1, len(nums)):
                complement = -(nums[i] + nums[j])
                if complement in complements:
                    triplet_set.add(tuple(sorted((nums[i], nums[j], complement))))
                    complements.remove(complement)
                complements.add(nums[j])
        return list(triplet_set)