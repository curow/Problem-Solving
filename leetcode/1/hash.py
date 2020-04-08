class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, num in enumerate(nums):
            if num not in m:
                m[num] = [i]
            else:
                m[num].append(i)
        for i, num in enumerate(nums):
            complement = target - num
            if complement in m:
                lst = m[complement]
                for j in lst:
                    if j == i:
                        continue
                    else:
                        return [i, j]
