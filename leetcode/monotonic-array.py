class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        sign = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                continue
            elif sign == 0:
                sign = 1 if nums[i] > nums[i-1] else -1
            else:
                if (nums[i] - nums[i-1]) * sign < 0:
                    return False
        return True
