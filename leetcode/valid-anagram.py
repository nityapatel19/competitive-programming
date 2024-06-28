class Solution:
    ## O(n logn)
    # def isAnagram(self, s: str, t: str) -> bool:
    #     return sorted(s) == sorted(t)

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        freqs = {}
        for letter in s:
            if letter not in freqs:
                freqs[letter] = 0
            freqs[letter] += 1
        
        for letter in t:
            if letter not in freqs: return False
            elif freqs[letter] < 1: return False
            else: freqs[letter] -= 1
        
        return True
