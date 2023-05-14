class Solution {
public:
    int maxScoreHelper(vector<int>& nums, int mask, int iter, vector<int>& dp, int &n) {
        if (dp[mask] != -1) return dp[mask];

        dp[mask] = 0;
        for (int i = 0; i < n; i++)
        {
            if ((1<<i) & mask) continue;
            for (int j = i+1; j < n; j++)
            {
                if ((1<<j) & mask) continue;
                int new_mask = mask | (1<<i) | (1<<j);
                int score = (iter * gcd(nums[i], nums[j]));
                dp[mask] = max(dp[mask], score + maxScoreHelper(nums, new_mask, iter+1, dp, n));
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1<<14, -1);
        return maxScoreHelper(nums, 0, 1, dp, n);
    }
};
