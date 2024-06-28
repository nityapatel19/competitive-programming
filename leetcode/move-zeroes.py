class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        k = 0
        while k < len(nums):
            if nums[k] != 0:
                nums[i], nums[k] = nums[k], nums[i]
                i += 1
            k += 1            
