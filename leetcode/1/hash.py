class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            val = target - x
            if val in d:
                return d[val], i
            else:
                d[x] = i
