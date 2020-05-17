from functools import reduce
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        products_end_in = [x for x in nums]
        for i in range(1, size):
            products_end_in[i] *= products_end_in[i - 1]
        products_start_from = [x for x in nums]
        for i in range(size - 2, -1, -1):
            products_start_from[i] *= products_start_from[i + 1]
        products_exclude_itself = [1 for i in range(size)]
        for i in range(size):
            if i < size - 1:
                products_exclude_itself[i] *= products_start_from[i + 1]
            if i > 0:
                products_exclude_itself[i] *= products_end_in[i - 1]
        return products_exclude_itself

