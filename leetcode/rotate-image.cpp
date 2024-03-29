class Solution {
public:
    /* void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n-2*i-1; j++)
            {
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-1-i-j][i];
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = temp;
            }
        }
    } */

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int start = 0; start < n/2; start++)
        {
            int end = n-start-1;
            for (int i = start; i < end; i++)
            {
                int temp = matrix[start][i];
                matrix[start][i] = matrix[n-i-1][start];
                matrix[n-i-1][start] = matrix[end][n-i-1];
                matrix[end][n-i-1] = matrix[i][end];
                matrix[i][end] = temp;
            }
        }
    }
};
