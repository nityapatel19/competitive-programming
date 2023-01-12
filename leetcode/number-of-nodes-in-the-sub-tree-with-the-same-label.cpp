class Solution {
public:
    // Returns the frequency of all characters in the subtree.
    vector<int> dfs(int parent, int current, map<int, vector<int>>& adj_list, string& labels, vector<int>& answer)
    {
        vector<int> char_freq(26);
        for (auto child: adj_list[current])
        {
            if (child == parent) continue;
             
            vector<int> result = dfs(current, child, adj_list, labels, answer);
            for (int i = 0; i < 26; ++i)
            {
                char_freq[i] += result[i];
            }
        }
        answer[current] = ++char_freq[labels[current] - 'a'];
        return char_freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> answer(n);
        map<int, vector<int>> adj_list;
        for (auto& edge: edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        dfs(-1, 0, adj_list, labels, answer);
        return answer;        
    }
};