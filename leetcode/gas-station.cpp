class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), i = 0;
        int diff[n] = {0};

        for (int i = 0; i < n; ++i)
        {
            diff[i] = gas[i] - cost[i];
        }

        int max_yet = 0, curr_sum = 0, left = 0, right = 0;
        for (int i = 0; i < n; ++i)
        {
            curr_sum += diff[i];
            if (curr_sum < 0)
            {
                curr_sum = 0;
                left = i+1;
            }
            
            if (curr_sum > max_yet)
            {
                right = i;
                max_yet = curr_sum;
            }
        }

        return left;
    }
};