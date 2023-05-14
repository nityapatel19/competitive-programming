class Solution {
public:
    // Slow!
    /* int modulus = 1e9+7;
    int countGoodStringsHelper(int len, int low, int high, int zero, int one, map<int, int>& dp) {
        if (dp.find(len) != dp.end()) return dp[len];
        if (len > high) return 0;

        dp[len] = len>=low ? 1 : 0;
        dp[len] += countGoodStringsHelper(len+zero, low, high, zero, one, dp) % modulus;
        dp[len] += countGoodStringsHelper(len+one, low, high, zero, one, dp) % modulus;

        return dp[len] % modulus;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        map<int, int> dp;
        return countGoodStringsHelper(0, low, high, zero, one, dp);
    } */

    // Fast! Use array instead of map.
    int countGoodStrings(int low, int high, int zero, int one) {
        int modulus = 1e9+7;
        int dp[high+1];
        dp[0] = 1;
        int count = 0;
        for (int i = 1; i <= high; i++)
        {
            dp[i] = (((i-zero)>=0 ? dp[i-zero] : 0) + ((i-one)>=0 ? dp[i-one] : 0))%modulus;
            if (i >= low) count = (count + dp[i])%modulus;
        }
        return count;
    }
};
