class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.length();
        // 2*numRows-2 characters -> numRows-1 columns
        // int numCols = (numRows-1) * (n/(2*numRows-2)+1);
        int numCols = n/2 + numRows;
        vector<vector<char>> M(numRows, vector<char>(numCols,' ')); 
        char x = 'd'; // {'d': down, 'u': up}
        int row = 0, col = 0;
        for (char c: s)
        {
            M[row][col] = c;
            switch (x)
            {
                case 'd':
                    if (row+1 < numRows)
                    {
                        row++;
                    }
                    else
                    {
                        row--;
                        col++;
                        x = 'u';
                    }
                    break;
                case 'u':
                    if (row-1 >= 0)
                    {
                        row--;
                        col++;
                    }
                    else
                    {
                        row++;
                        x = 'd';
                    }
                    break;
            }
        }

        string answer = "";
        for (row = 0; row < numRows; row++)
        {
            for (col = 0; col < numCols; col++)
            {
                if (M[row][col] != ' ')
                {
                    answer += M[row][col];
                }
            }
        }
        return answer;
    }
};