class Solution {
public:
    /* vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    st.insert({nums[i], nums[left], nums[right]});
                    left++; right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }

        vector<vector<int>> ans;
        for (auto x: st)
        {
            ans.push_back(x);
        }
        return ans;
    } */

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;

                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
};