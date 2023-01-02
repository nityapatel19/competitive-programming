class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals_count = 0;
        for (char c: word)
        {
            if (isupper(c))
            {
                capitals_count++;
            }
        }
        if (isupper(word[0]))
        {
            return capitals_count == 1 || capitals_count == word.length();
        }
        else
        {
            return capitals_count == 0;
        }
    }
};