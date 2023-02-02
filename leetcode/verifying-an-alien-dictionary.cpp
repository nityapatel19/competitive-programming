class Solution {
public:
    bool compare(string a, string b, string order) {
        int i = 0;
        while (i < a.length() && i < b.length())
        {
            if (order.find(a[i]) < order.find(b[i]))
                return true;
            if (order.find(a[i]) > order.find(b[i]))
                return false;
            i++;
        }
        return a.length() <= b.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 1; i < words.size(); i++)
        {
            if (!compare(words[i-1], words[i], order))
                return false;
        }
        return true;
    }
};