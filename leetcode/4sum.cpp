class Solution {
public:
    // Time: O(n^3) or O(n^3 logn) if we consider set.
    /* vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans_set;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                set<long> hash;
                for (int k = j+1; k < n; k++)
                {
                    long leftover = (long)target-nums[i]-nums[j]-nums[k];
                    if (hash.find(leftover) != hash.end())
                    {
                        vector<int> temp({nums[i], nums[j], nums[k], (int)leftover});
                        sort(temp.begin(), temp.end());
                        ans_set.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }        
        return vector<vector<int>>(ans_set.begin(), ans_set.end());
    } */

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = n-1;
                while (k < l)
                {
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k-1]) k++;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }        
        return ans;
    }
};
