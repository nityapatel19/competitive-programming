class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int cols = strs.size(), rows = strs[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (strs[j][i] < strs[j-1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};