class Solution {
public:
    void helper(vector<int>& nums, int i, int target, vector<int> arr, vector<vector<int>>& ans) {
        if (target == 0)
        {
            ans.push_back(arr);
            return;
        }
        if (target < 0 || i == nums.size()) return;

        // Not including i
        helper(nums, i+1, target, arr, ans);
        // Including i
        arr.push_back(nums[i]);
        helper(nums, i, target-nums[i], arr, ans);
        arr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(candidates, 0, target, arr, ans);
        return ans;
    }
};
