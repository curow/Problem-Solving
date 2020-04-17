from functools import lru_cache
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        final = len(nums) - 1
        @lru_cache(maxsize=None)
        def jump(current_pos):
            if current_pos >= final:
                return True
            k = nums[current_pos]
            return any([jump(current_pos + i) for i in range(k, 0, -1)])
        return jump(0)


