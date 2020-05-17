class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        L, R, products_exclude_itself = [0] * size, [0] * size, [0] * size
        # L contains products of number to its left exclude itself
        L[0] = 1
        for i in range(1, size):
            L[i] = L[i - 1] * nums[i - 1]
        # R contains products of number to its right exclude itself
        R[-1] = 1
        for i in reversed(range(size - 1)):
            R[i] = R[i + 1] * nums[i + 1]
        # now we combine these two list
        for i in range(size):
            products_exclude_itself[i] = L[i] * R[i]
        return products_exclude_itself
