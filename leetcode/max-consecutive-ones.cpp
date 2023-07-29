class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_yet = 0, curr = 0, n = nums.size();
        if (nums[0] == 1)
        {
            curr = 1; max_yet = 1;
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 1)
            {
                curr++;
                max_yet = max(max_yet, curr);
            }
            else curr = 0;
        }
        return max_yet;
    }
};
