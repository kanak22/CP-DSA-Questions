class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        l = [(-1, 0)] # here the list l will serve as the stack 

        for i, j in enumerate(heights + [0]):
            if l[-1][1] < j:
                l.append((i, j))
            else:
                while l[-1][1] > j:
                    pre_i,pre_j = l.pop()
                    ans = max(ans, pre_j * (i - pre_i))
                if l[-1][1] < j:
                    l.append((pre_i, j))
        return ans
