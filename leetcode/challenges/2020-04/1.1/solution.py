class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bits = 0
        for num in nums:
            bits ^= num
        return bits
