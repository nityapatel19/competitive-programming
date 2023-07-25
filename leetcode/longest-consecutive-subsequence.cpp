class Solution {
public:
    // Time: O(n logn)
    /* int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int count = 1, max_count = 1, last_num = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == last_num) continue;
            if (nums[i] == 1 + last_num) count++;
            else
            {
                max_count = max(max_count, count);
                count = 1;
            }
            last_num = nums[i];
        }
        max_count = max(max_count, count);
        return max_count;
    } */

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_count = 0;
        for (const int& num: st)
        {
            if (st.find(num-1) != st.end()) continue;
            int count = 1, x = num;
            while (st.find(x+1) != st.end())
            {
                count++;
                x++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
