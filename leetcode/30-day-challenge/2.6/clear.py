class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            if num == 0:
                nums[i] = -1
        size = len(nums)
        dp = [[float('inf') for j in range(size)] for i in range(size)]
        best = 0
        for i in range(size):
            dp[i][0] = nums[i]
        for i in range(1, size):
            for j in range(1, i + 1):
                dp[i][j] = dp[i][0] + dp[i - 1][j - 1]
                if dp[i][j] == 0:
                    best = max(best, j + 1)
        for j in range(size - 1, -1, -1):
            if dp[size - 1][j] == 0:
                return j + 1
        return 0
