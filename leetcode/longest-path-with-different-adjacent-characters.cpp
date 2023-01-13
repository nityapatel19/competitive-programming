class Solution {
public:
    int dfs(int curr, vector<vector<int>>& adj_list, string& s, int& answer)
    {
        if (adj_list[curr].size() == 0) return 1;
        // max_len_1 > max_len_2 are two longest chains in subtree.
        int max_len_1 = 0, max_len_2 = 0;
        for (auto child: adj_list[curr])
        {
            int temp = dfs(child, adj_list, s, answer);
            if (s[child] == s[curr]) temp = 0;

            if (temp > max_len_1)
            {
                max_len_2 = max_len_1;
                max_len_1 = temp;
            }
            else if (temp > max_len_2)
            {
                max_len_2 = temp;
            }
        }
        answer = max(answer, max_len_1+max_len_2+1);
        return max_len_1+1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj_list(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == -1) continue;
            adj_list[parent[i]].push_back(i);
        }
        int answer = 1;
        dfs(0, adj_list, s, answer);
        return answer;
    }
};