class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if k < 0:
            k = -k
            nums = [-x for x in nums]
        slow, fast = 0, 0
        count = 0
        total = nums[0]
        while fast < len(nums) and slow < len(nums):
            if total == k:
                count += 1
            if fast + 1 < len(nums) and total + nums[fast + 1] <= k:
                fast += 1
                total += nums[fast]
            else:
                total -= nums[slow]
                slow += 1
        return count
