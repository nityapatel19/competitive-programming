class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> new_intervals;
        bool not_crossed_interval = true;
        int left = newInterval[0], right = newInterval[1];
        for (int i = 0; i < n; i++)
        {
            if (left > intervals[i][1])
            {
                new_intervals.push_back(intervals[i]);
            }
            else if (right < intervals[i][0])
            {
                if (not_crossed_interval)
                {
                    new_intervals.push_back({left, right});
                    not_crossed_interval = false;
                }
                new_intervals.push_back(intervals[i]);
            }
            else
            {
                left = min(intervals[i][0], left);
                right = max(intervals[i][1], right);
            }
        }
        if (not_crossed_interval)
        {
            new_intervals.push_back({left, right});
        }
        return new_intervals;
    }
};