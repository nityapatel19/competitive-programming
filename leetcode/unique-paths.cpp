class Solution {
public:
    // Too slow, TLE. Time: O(2^n), Space: O(2^n) (Only due to recursion stack)
    /* int uniquePathsHelper(int i, int j, int m, int n) {
        if (i >= m || j >= n) return 0;
        if (i == m-1 && j == n-1) return 1;
        return uniquePathsHelper(i+1,j,m,n) + uniquePathsHelper(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return uniquePathsHelper(0,0,m,n);
    } */

    // Using DP to reduce time complexity of the above recursive algorithm. Time: O(m*n), Space: O(m*n)
    /* int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i >= m || j >= n) return 0;
        if (i == m-1 && j == n-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = uniquePathsHelper(i+1,j,m,n,dp) + uniquePathsHelper(i,j+1,m,n,dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePathsHelper(0,0,m,n,dp);
    } */

    // Mathematical Solution. Time: O(min(m,n)), Space: O(1)
    int uniquePaths(int m, int n) {
        // We need to take m-1 steps down, and n-1 steps right.
        m--; n--;
        // Now, Answer = (m+n)!/m!n!
        // If m > n, we take (m+n)(m+n-1)...(m+1)/n!
        long ans = 1;
        int x = min(m,n);
        for (int i = 0; i < x; i++)
        {
            ans = ans * (m+n-i)/(i+1);
        }
        return ans;
    }
};
