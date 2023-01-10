class Solution {
// Slow due to different functions.
/*private:
    double slope(vector<int> p1, vector<int> p2) {
        int dx = p2[0]-p1[0];
        int dy = p2[1]-p1[1];

        if (dx == 0)
        {
            return DBL_MAX;
        }
        
        return dy/(double)dx;
    }
public:
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
    }*/
public:
    // Still not the fastest.
    /*int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), max_points = 0;
        double m;
        for (int i = 0; i < n; ++i)
        {
            map<double, int> slope_freq;
            for (int j = 0; j < n; ++j)
            {
                if (i == j) continue;

                m = (points[i][0] != points[j][0]) ? (points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]) : DBL_MAX;
                slope_freq[m]++;
                max_points = max(max_points, slope_freq[m]);
            }
        }
        return max_points+1;
    }*/

    // Faster. Iterates less. Just checks overall which slopes are most common.
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), max_points = 0;
        double m;
        for (int i = 0; i < n; ++i)
        {
            map<double, int> slope_freq;
            for (int j = i+1; j < n; ++j)
            {
                if (i == j) continue;

                m = (points[i][0] != points[j][0]) ? (points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]) : DBL_MAX;
                slope_freq[m]++;
                max_points = max(max_points, slope_freq[m]);
            }
        }
        return max_points+1;
    }
};