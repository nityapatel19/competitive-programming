class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
        {
            return trust.size() == 0 ? 1 : -1;
        }

        vector<int> trust_count(n+1,0);
        vector<int> trusted_count(n+1,0);
        for (auto trust_pair: trust)
        {
            trust_count[trust_pair[0]]++;
            trusted_count[trust_pair[1]]++;
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (trust_count[i] == 0 && trusted_count[i] == n-1)
            {
                return i;
            }
        }

        return -1;
    }
};