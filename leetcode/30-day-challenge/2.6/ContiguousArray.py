class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        best = 0
        size = len(nums)
        for i in range(1, size):
            radius = 1
            prev_left_index = i - radius
            prev_right_index = i + radius - 1
            if nums[prev_left_index] != nums[prev_right_index]:
                while prev_left_index >= 1 and prev_right_index < size - 1:
                    if nums[prev_left_index - 1] == nums[prev_left_index] \
                            and nums[prev_right_index + 1] == nums[prev_right_index]:
                        radius += 1
                        prev_left_index -= 1
                        prev_right_index += 1
                    else:
                        break
                best = max(best, radius)
        return best * 2

