class Solution:
    ## Hehe
    # def strStr(self, haystack: str, needle: str) -> int:
    #     return haystack.find(needle)

    def strStr(self, haystack: str, needle: str) -> int:
        len_needle = len(needle)
        len_haystack = len(haystack)
        for i, letter in enumerate(haystack):
            if letter == needle[0] and i + len_needle <= len_haystack:
                if haystack[i:i+len_needle] == needle:
                    return i
        return -1
