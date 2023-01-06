class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (auto cost: costs)
        {
            if (cost <= coins)
            {
                count++;
                coins -= cost;
            }
        }
        return count;
    }
};