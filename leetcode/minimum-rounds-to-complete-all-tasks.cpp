class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> freq;
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i]]++;
        }

        int count = 0;
        for (auto x: freq)
        {
            if (x.second == 1)
            {
                return -1;
            }
            else if (x.second%3 == 0)
            {
                count += x.second/3;
            }
            else
            {
                count += (x.second/3+1);
            }
        }
        return count;
    }
};