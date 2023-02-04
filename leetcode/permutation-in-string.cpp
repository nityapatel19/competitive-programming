class Solution {
public:
    // Slow. Use hashmap instead of multiset.
    /*bool checkInclusion(string s1, string s2) {
        int left = 0, right = s1.length();
        int n = s2.length();
        if (n < right) return false;

        multiset<char> letters(s1.begin(), s1.end());
        multiset<char> window(s2.begin()+left, s2.begin()+right);
        do
        {
            if (window == letters)
            {
                return true;
            }
            window.erase(window.find(s2[left++]));
            window.insert(s2[right++]);
        } while (right <= n);

        return false;
    }*/

    // Faster. More efficient.
    bool is_equal(int a[26], int b[26]) {
        for (int i = 0; i < 26; ++i)
            if (a[i] != b[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = s1.length();
        int n = s2.length();
        if (n < right) return false;

        int letters[26] = {0};
        int window[26] = {0};
        for (int i = 0; i < right; i++)
        {
            letters[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        do
        {
            if (is_equal(letters, window))
            {
                return true;
            }
            window[s2[left++]-'a']--;
            window[s2[right++]-'a']++;
        } while (right <= n);

        return false;
    }
};