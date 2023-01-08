class Solution {
public:
    double slope(vector<int> p1, vector<int> p2) {
        double dx = p2[0]-p1[0];
        double dy = p2[1]-p1[1];

        if (dx == 0)
        {
            return DBL_MAX;
        }
        
        return dy/dx;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), max_points = 0;
        double m;
        for (int i = 0; i < n; ++i)
        {
            map<double, int> slope_freq;
            for (int j = 0; j < n; ++j)
            {
                if (i == j) continue;

                m = slope(points[i], points[j]);
                slope_freq[m]++;
                max_points = max(max_points, slope_freq[m]);
            }
        }
        return max_points+1;
    }
};