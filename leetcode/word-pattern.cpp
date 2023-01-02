class Solution {
public:
    // It is not slow.
    /*bool wordPattern(string pattern, string s) {
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
    }*/

    // Just a different approach.
    bool wordPattern(string pattern, string s) {
        map<char, string> c2s;
        map<string, char> s2c;

        stringstream sentence(s);
        string word;
        vector<string> words;
        while (sentence >> word)
        {
            words.push_back(word);
        }

        if (words.size() != pattern.length())
        {
            return false;
        }

        for (int i = 0; i < pattern.length(); i++)
        {
            c2s[pattern[i]] = words[i];
            s2c[words[i]] = pattern[i];
        }
        
        for (int i = 0; i < pattern.length(); i++)
        {
            if (c2s[pattern[i]] != words[i] || s2c[words[i]] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};