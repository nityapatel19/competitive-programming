class Solution {
public:
    bool checkInclusion(string s1, string s2) {
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
    }
};