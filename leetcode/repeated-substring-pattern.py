class Solution:
    # O(n^2)
    # def repeatedSubstringPattern(self, s: str) -> bool:
    #     n = len(s)

    #     for i in range(1, n):
    #         if n%i == 0:
    #             if s == s[:i] * (n//i):
    #                 return True

    #     return False

    def repeatedSubstringPattern(self, s: str) -> bool:
        '''
        The operation s in s_fold checks if s is a substring of s_fold.
        The worst-case time complexity for substring search is O(m*n),
        where m is the length of s_fold (which is 2n - 2, approximately
        2n for large n) and n is the length of s. However, modern Python
        implementations use efficient algorithms like Boyer-Moore or
        Knuth-Morris-Pratt for substring search, which have a better
        average and best-case time complexity. For the sake of simplicity,
        we can consider this operation to be O(n) in the average case,
        acknowledging that the worst-case scenario can be more costly.
        '''
        s_fold = s[1:] + s[:-1]
        return s in s_fold
