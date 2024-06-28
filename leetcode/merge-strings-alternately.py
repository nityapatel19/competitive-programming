class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        size1, size2 = len(word1), len(word2)
        result = [0] * (size1 + size2)
        
        i, j, k = 0, 0, 0
        while i < size1 and j < size2:
            result[k], result[k+1] = word1[i], word2[j]
            i += 1
            j += 1
            k += 2
        
        while i < size1:
            result[k] = word1[i]
            i += 1
            k += 1
        
        while j < size2:
            result[k] = word2[j]
            j += 1
            k += 1
         
        return ''.join(result)
