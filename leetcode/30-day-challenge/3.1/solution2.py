class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        answer = [1] * size
        for i in range(1, size):
            answer[i] = answer[i - 1] * nums[i - 1]
        R = 1
        for i in reversed(range(size)):
            answer[i] *= R
            R *= nums[i]
        return answer

