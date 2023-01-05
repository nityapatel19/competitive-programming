class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1, num_points = points.size();

        int last_end = points[0][1];

        for (int i = 1; i < num_points; ++i)
        {
            if (points[i][0] > last_end)
            {
                count++;
                last_end = points[i][1];
            }

            last_end = min(last_end, points[i][1]);
        }

        return count;
    }
};