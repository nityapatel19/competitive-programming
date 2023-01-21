class Solution {
public:
    bool valid_octet(string s) {
        if (s.length() > 3 || s.length() == 0) return false;
        if (s.length() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
    void search(int idx, int dots, string& s, string& curr_str, vector<string>& ans) {
        if (dots == 3)
        {
            if (valid_octet(s.substr(idx)))
            {
                ans.push_back(curr_str+s.substr(idx));
            }
            return;
        }

        int n = s.length();
        for (int i = idx; i < min(idx + 3, n); i++)
        {
            if (valid_octet(s.substr(idx, i-idx+1)))
            {
                curr_str += s[i];
                curr_str += '.';
                search(i+1, dots+1, s, curr_str, ans);
                curr_str.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        string temp;
        search(0, 0, s, temp, answer);
        return answer;
    }
};