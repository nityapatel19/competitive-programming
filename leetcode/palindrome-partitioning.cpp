class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
    void helper(string& s, int i, vector<string>& arr, vector<vector<string>>& ans) {
        int n = s.length();
        if (i > n) return;
        if (i == n)
        {
            ans.push_back(arr);
            return;
        }

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                arr.push_back(s.substr(i, j+1-i));
                helper(s, j+1, arr, ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        helper(s, 0, arr, ans);
        return ans;
    }
};
