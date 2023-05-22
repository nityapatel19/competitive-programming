class Solution {
public:
    /* static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size(), prev = 0, count = 0;
        if (n == 0) return 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[prev][1] > intervals[i][0])
                count++;
            else
                prev = i;
        }
        return count;
    } */

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int n = intervals.size(), prev = 0, count = 0;
        if (n == 0) return 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[prev][1] > intervals[i][0])
                count++;
            else
                prev = i;
        }
        return count;
    }
};
