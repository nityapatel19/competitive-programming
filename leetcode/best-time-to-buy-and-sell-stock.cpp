class Solution {
public:
    // Keep track of current minimum and move forward.
    int maxProfit(vector<int>& prices) {
        int curr_min = prices[0], profit = 0;
        for (int &price: prices)
        {
            profit = max(profit, price-curr_min);
            curr_min = min(curr_min, price);
        }
        return profit;
    }
};
