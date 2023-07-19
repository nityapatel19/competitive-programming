class Solution {
public:
    // Kadane's Algorithm -> Drop when curr_sum goes negative as it will only reduce future sums.
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for (int &num: nums)
        {
            curr_sum += num;
            max_sum = max(curr_sum, max_sum);
            if (curr_sum < 0)
            {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};
