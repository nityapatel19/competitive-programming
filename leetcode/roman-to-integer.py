class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                  'C': 100, 'D': 500, 'M': 1000}
        nums = 0
        for i in range(len(s)):
            if i < len(s) - 1 and romans[s[i]] < romans[s[i + 1]]:
                nums -= romans[s[i]]
            else:
                nums += romans[s[i]]
        return nums
