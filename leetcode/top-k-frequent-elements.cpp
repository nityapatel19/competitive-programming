class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pairs;
        for (auto iter: freq)
        {
            pairs.push({iter.second, iter.first});
        }

        vector<int> answer;
        for (int i = 0; i < k; ++i)
        {
            answer.push_back(pairs.top());
            pairs.pop();
        }
        return answer;
    }
};