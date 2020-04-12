class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(len(nums) - 1, -1, -1):
            if i + 1 < len(nums):
                nums[i] = max(nums[i], nums[i] + nums[i + 1])
        return max(nums)
