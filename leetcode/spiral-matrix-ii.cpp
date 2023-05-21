class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n));
        int left = 0, right = n-1, up = 0, down = n-1;

        int curr = 1;
        while(curr <= n*n)
        {
            for (int i = left; i <= right; i++)
                M[up][i] = curr++;
            up++;
            
            for(int i = up; i <= down; i++)
                M[i][right] = curr++;
            right--;

            for(int i = right; i >= left; i--)
                M[down][i] = curr++;
            down--;
        
            for(int i = down; i >= up; i--)
                M[i][left] = curr++;
            left++;
        }
        return M;
    }
};
