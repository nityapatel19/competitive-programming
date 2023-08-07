class Solution {
public:
    /* void helper(vector<int>& nums, int i, vector<int> arr, set<vector<int>>& ans) {
        if (i == nums.size())
        {
            ans.insert(arr);
            return;
        }
        helper(nums, i+1, arr, ans);
        arr.push_back(nums[i]);
        helper(nums, i+1, arr, ans);
        arr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> arr;
        helper(nums, 0, arr, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    } */

    void helper(vector<int>& nums, int sz, vector<int> arr, vector<vector<int>>& ans) {
        ans.push_back(arr);
        int n = nums.size();
        for (int i = sz; i < n; i++)
        {
            if (i > sz && nums[i]==nums[i-1]) continue;
            arr.push_back(nums[i]);
            helper(nums, i+1, arr, ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> arr;
        helper(nums, 0, arr, ans);
        return ans;
    }
};
