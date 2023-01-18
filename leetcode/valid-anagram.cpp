class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        map<char, int> letter_freq;
        for (char c: s)
        {
            letter_freq[c]++;
        }

        for (char c: t)
        {
            if (letter_freq.find(c) == letter_freq.end()) return false;
            else if (letter_freq[c] < 1) return false;
            else letter_freq[c]--;
        }
        return true;
    }
};