class Solution:
    ## Okay.
    # def findTheDifference(self, s: str, t: str) -> str:
    #     frequencies = [0]*26
    #     letters = "abcdefghijklmnopqrstuvwxyz"
    #     for letter in s:
    #         frequencies[letters.index(letter)] += 1
    #     for letter in t:
    #         frequencies[letters.index(letter)] -= 1
    #         if frequencies[letters.index(letter)] < 0:
    #             return letter

    ## Still okay.
    # def findTheDifference(self, s: str, t: str) -> str:
    #     for letter in t:
    #         if s.count(letter) < t.count(letter):
    #             return letter
    
    ## Bitwise!
    def findTheDifference(self, s: str, t: str) -> str:
        merged = s + t
        res = 0
        for letter in merged:
            res ^= ord(letter)        
        return chr(res)
