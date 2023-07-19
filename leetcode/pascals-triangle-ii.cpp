class Solution {
public:
    // Nothing wrogn, equally good.
    /* vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (rowIndex == 0) return {1};
        ans.push_back({1,1});
        if (rowIndex == 1) return {1,1};

        for (int i = 2; i < rowIndex+1; i++)
        {
            vector<int> temp(i+1, 1);
            for (int j = 1; j < i; j++)
            {
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans[rowIndex];
    } */

    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; i++)
        {
            ans[i] = (long)ans[i-1] * (long)(rowIndex+1-i) / (long)(i);
        }
        return ans;
    }
};