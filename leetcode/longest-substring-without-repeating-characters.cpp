class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int maxlen = 0, start = 0, i;
        map<int,int> mp;
        for (i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end() && mp[s[i]]>=start)
            {
                maxlen = max(maxlen, i-start);
                start = mp[s[i]]+1;
            }
            mp[s[i]] = i;
        }
        maxlen = max(maxlen, i-start);
        return maxlen;
    }
};
