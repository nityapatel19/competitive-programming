class Solution {
public:
    // Kind of slow.
    /* bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][m-1] < target) continue;
            if (matrix[i][0] > target) break;

            int start = 0, end = m-1, mid;
            while (start <= end)
            {
                mid = (start+end)/2;
                if (matrix[i][mid] < target) start = mid+1;
                else if (matrix[i][mid] > target) end = mid-1;
                else return true;
            }
        }
        return false;
    } */

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n-1;
        while (row < m && col >= 0)
        {
            if (matrix[row][col] > target) col--;
            else if (matrix[row][col] < target) row++;
            else return true;
        }
        return false;
    }
};
