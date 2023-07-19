class Solution {
public:
    // Time: O(m*n) Good
    // Space: O(m+n) Could be better?
    /* void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        set<int> zeroed_rows, zeroed_cols;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                {
                    zeroed_rows.insert(i);
                    zeroed_cols.insert(j);
                }
        
        for (int row: zeroed_rows)
            for (int i = 0; i < cols; i++)
                matrix[row][i] = 0;
        for (int col: zeroed_cols)
            for (int i = 0; i < rows; i++)
                matrix[i][col] = 0;
    } */

    // Space: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col_marker_0 = 1;
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j == 0)
                        col_marker_0 = 0;
                    else
                        matrix[0][j] = 0;
                }
        
        // Update non-marker elements first
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        // Update column markers next
        if (matrix[0][0] == 0)
            for (int j = 1; j < cols; j++)
                matrix[0][j] = 0;
        
        // Update the row markers last as they are independent
        if (col_marker_0 == 0)
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};