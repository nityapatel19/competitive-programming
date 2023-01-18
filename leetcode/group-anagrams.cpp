class Solution {
public:
    // Slow and inefficient.
    /*vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<multiset<char>, int> char_set_to_index;
        int groups = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
            multiset<char> temp(strs[i].begin(), strs[i].end());
            if (char_set_to_index.find(temp) != char_set_to_index.end())
            {
                answer[char_set_to_index[temp]].push_back(strs[i]);
            }
            else
            {
                char_set_to_index[temp] = groups++;
                answer.push_back({strs[i]});
            }
        }
        return answer;
    }*/

    // Faster!
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<string, vector<string>> groups;
        for (string s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            groups[t].push_back(s);
        }
        for (auto iter: groups)
        {
            answer.push_back(iter.second);
        }
        return answer;
    }
};