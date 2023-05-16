class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> temp;
        for (auto v: intervals)
        {
            temp.push_back(make_pair(v[0], v[1]));
        }
        sort(temp.begin(), temp.end());

        vector<vector<int>> ans;
        int start = temp[0].first;
        int end = temp[0].second;
        for (int i = 1; i < temp.size(); ++i)
        {
            if (temp[i].first <= end)
                end = max(temp[i].second, end);
            else
            {
                ans.push_back({start, end});
                start = temp[i].first;
                end = temp[i].second;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};