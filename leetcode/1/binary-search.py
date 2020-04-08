class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        def binary_search(nums_with_index, val, lo, hi):
            if lo > hi or lo < 0 or hi >= len(nums_with_index):
                return -1
            mid = lo + (hi - lo) // 2
            x = nums_with_index[mid][0]
            if val > x:
                return binary_search(nums_with_index, val, mid + 1, hi)
            elif val < x:
                return binary_search(nums_with_index, val, lo, mid - 1)
            else:
                return nums_with_index[mid][1]
            
        n = len(nums)
        nums_with_index = [[x, i] for i, x in enumerate(nums)]
        nums_with_index = sorted(nums_with_index)
        for index, (x, i) in enumerate(nums_withindex):
            val = target - x
            j = binary_search(nums_with_index, val, index + 1, n - 1)
            if j != -1:
                return min(i, j), max(i, j)
