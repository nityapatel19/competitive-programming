class Solution {
public:
    void helper(vector<int>& nums, int sz, int target, vector<int> arr, vector<vector<int>>& ans) {
        if (target == 0)
        {
            ans.push_back(arr);
            return;
        }
        if (target < 0) return;

        int n = nums.size();
        for (int i = sz; i < n; i++)
        {
            if (i > sz && nums[i] == nums[i-1]) continue;
            if (nums[i] > target) break;
            arr.push_back(nums[i]);
            helper(nums, i+1, target-nums[i], arr, ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        helper(candidates, 0, target, arr, ans);
        return ans;
    }
};
