class Solution {
public:
    bool is_equal(int a[26], int b[26]) {
        for (int i = 0; i < 26; ++i)
            if (a[i] != b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = p.length();
        int n = s.length();
        if (n < right) return {};

        vector<int> answer;
        int letters[26] = {0};
        int window[26] = {0};
        for (int i = 0; i < right; i++)
        {
            letters[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        do
        {
            if (is_equal(letters, window))
            {
                answer.push_back(left);
            }
            if (right < n)
            {
                window[s[left]-'a']--;
                window[s[right]-'a']++;
            }
            left++; right++;
        } while (right <= n);

        return answer;
    }
};