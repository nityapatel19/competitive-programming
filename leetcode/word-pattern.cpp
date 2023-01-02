class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp; // character to word
        set<string> visited; // visited words
        int j = 0; // pointer in s
        for(int i = 0; i < pattern.length(); i++)
        {
            // Extract the next word from s
            string word = "";
            while(j < s.length() && s[j] != ' ')
            {
                word += s[j];
                j++;
            }
            j++;

            // If no word, means pattern is longer.
            if (word.length() == 0)
            {
                return false;
            }

            if (visited.find(word) == visited.end())
            {
                if (mp.find(pattern[i]) == mp.end())
                {
                    mp[pattern[i]] = word;
                    visited.insert(word);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (mp.find(pattern[i]) == mp.end() || mp[pattern[i]] != word)
                {
                    return false;
                }
            }
        }

        // Words are more, pattern is shorter.
        if (j < s.length())
            return false;

        return true;
    }
};