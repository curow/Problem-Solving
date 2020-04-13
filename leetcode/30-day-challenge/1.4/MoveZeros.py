class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last = len(nums)
        while True:
            try:
                index = nums.index(0, 0, last)
                nums.pop(index)
                nums.append(0)
                last -= 1
            except:
                return
