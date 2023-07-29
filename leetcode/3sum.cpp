class Solution {
public:
    // Slow!
    /* vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i+1; j < n; j++)
            {
                int target = 0-nums[i]-nums[j];
                if (st.find(target) != st.end())
                {
                    vector<int> temp({nums[i], target, nums[j]});
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                st.insert(nums[j]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    } */

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] > 0) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else
                {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};