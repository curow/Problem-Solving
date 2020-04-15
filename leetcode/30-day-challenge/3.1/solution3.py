class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        answer = [1] * size
        L = 1
        for i in range(size):
            answer[i] *= L
            L *= nums[i]
        R = 1
        for i in reversed(range(size)):
            answer[i] *= R
            R *= nums[i]
        return answer

