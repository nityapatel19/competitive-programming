class Solution {
public:
    // I don't know why,
    // but if total gas > total cost,
    // a solution is always possible.
    /*int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), i = 0, sum = 0;
        vector<int> diff(n,0);
        for (i = 0; i < n; ++i)
        {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }

        if (sum < 0) return -1;

        int curr_sum = 0, left = 0;
        for (i = 0; i < n; i++)
        {
            curr_sum += diff[i];
            if (curr_sum < 0)
            {
                curr_sum = 0;
                left = i+1;
            }
        }
        return left;
    }*/

    // Little faster.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int curr_gas = 0;
        int starting_point = 0;

        for (int i = 0; i < n; ++i)
        {
            curr_gas += gas[i]-cost[i];
            balance += gas[i]-cost[i];
            if (curr_gas < 0)
            {
                starting_point = i+1;
                curr_gas = 0;
            }
        }
        return (balance >= 0 ? starting_point : -1);
    }
};