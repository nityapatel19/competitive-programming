class Solution {
private:
    int dfs_count_steps_to_apple(int parent, int current, vector<vector<int>>& adj_list, vector<bool>& hasApple)
    {
        int answer = 0;
        for (auto child: adj_list[current])
        {
            if (child == parent) continue;
            int result = dfs_count_steps_to_apple(current, child, adj_list, hasApple);
            if (result > 0 || hasApple[child])
            {
                answer += (result+2);
            }
        }
        return answer;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj_list(n);
        for (auto edge: edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        return dfs_count_steps_to_apple(-1, 0, adj_list, hasApple);
    }
};