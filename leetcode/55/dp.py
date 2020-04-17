class Solution:
    def canJump(self, nums: List[int]) -> bool:
        final = len(nums) - 1
        dp = [-1] * len(nums)
        dp[-1] = 1
        for i in reversed(range(0, final)):
            max_jumps = nums[i]
            max_position = min(i + max_jumps, final)
            for j in range(i + 1, max_position + 1):
                if dp[j] == 1:
                    dp[i] = 1
                    break
        return dp[0] == 1

