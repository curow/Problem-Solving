class Solution:
    def fib(self, N: int) -> int:
        dp = [0 for _ in range(max(2, N + 1))]
        dp[0], dp[1] = 0, 1
        for i in range(2, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[N]
        
