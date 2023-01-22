class Solution {
public:
    void search(int idx, vector<int>& nums, vector<int>& a, set<vector<int>>& ans) {
        int n = nums.size();

        if (idx >= n)
        {
            if (a.size() >= 2)
            {
                ans.insert(a);
            }
            return;
        }

        if (a.size() == 0 || nums[idx]>=a.back())
        {
            a.push_back(nums[idx]);
            search(idx+1, nums, a, ans);
            a.pop_back();
        }

        search(idx+1, nums, a, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> answer;
        search(0, nums, temp, answer);
        return vector(answer.begin(), answer.end());
    }
};