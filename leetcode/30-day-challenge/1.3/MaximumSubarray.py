class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = nums[0]
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i - 1] + nums[i])
            best = max(best, nums[i])
        return best
