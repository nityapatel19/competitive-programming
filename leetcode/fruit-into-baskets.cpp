class Solution {
public:
    // O(n^2). Slow.
    /*int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_count = INT_MIN;
        set<int> types;
        for (int left = 0; left < n; ++left)
        {
            int right = left;
            while (right < n)
            {
                if (types.find(fruits[right]) == types.end() && types.size() == 2)
                    break;

                types.insert(fruits[right]);
                right++;

            }
            types.clear();
            max_count = max(max_count, right-left);
        }
        return max_count;
    }*/

    // Much better, but can still be a little better.
    /*int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> basket;
        int left = 0, right = 0;
        int max_count = 0, curr_count = 0;

        while (right < n)
        {
            basket[fruits[right]]++;
            curr_count++;
            while (basket.size() > 2)
            {
                basket[fruits[left]]--;
                curr_count--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);

                left++;
            }
            max_count = max(max_count, curr_count);
            right++;
        }
        return max_count;
    }*/

    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> basket;
        int left = 0, right = 0;
        int max_count = 0, curr_count = 0;

        while (right < n)
        {
            basket[fruits[right]]++;
            curr_count++;
            // We can use if instead of while as the basket may not be valid,
            // but the last valid length is conserved.
            if (basket.size() > 2)
            {
                basket[fruits[left]]--;
                curr_count--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);

                left++;
            }
            max_count = max(max_count, curr_count);
            right++;
        }
        return max_count;
    }
};