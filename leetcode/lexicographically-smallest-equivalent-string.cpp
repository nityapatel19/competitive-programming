class Solution {
public:
    // Slow and inefficient!
    /*string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> sets;
        set<char> temp = {s1[0], s2[0]};
        sets.push_back(temp);
        int x1, x2;
        for (int i = 1; i < s1.length(); ++i)
        {
            x1 = -1; x2 = -1;
            for (int j = 0; j < sets.size(); j++)
            {
                if (sets[j].find(s1[i]) != sets[j].end())
                {
                    x1 = j;
                }
                if (sets[j].find(s2[i]) != sets[j].end())
                {
                    x2 = j;
                }
            }
            if (x1 == -1 && x2 == -1)
            {
                temp = {s1[i], s2[i]};
                sets.push_back(temp);
            }
            else if (x1 == -1)
            {
                sets[x2].insert(s1[i]);
            }
            else if (x2 == -1)
            {
                sets[x1].insert(s2[i]);
            }
            else
            {
                sets[x1].insert(sets[x2].begin(), sets[x2].end());
                if (x1 != x2)
                {
                    sets.erase(sets.begin()+x2);
                }
            }
        }

        string answer = "";
        bool found_letter;
        for (char c: baseStr)
        {
            found_letter = false;
            for (auto& st: sets)
            {
                if (st.find(c) != st.end())
                {
                    answer += *st.begin();
                    found_letter = true;
                }
            }
            if (!found_letter)
            {
                answer += c;
            }
        }
        return answer;
    }*/

    // Better solution!
    char find_least (char x, map<char,char>& mp)
    {
        if (mp.find(x) == mp.end()) return x;
        mp[x] = find_least(mp[x], mp);
        return mp[x];
    }
    void Union(char x, char y, map<char,char>& mp)
    {
        x = find_least(x, mp);
        y = find_least(y, mp);
        if (x != y)
            mp[max(x,y)] = min(x,y);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,char> mp;
        for (int i = 0; i < s1.length(); i++)
        {
            Union(s1[i], s2[i], mp);
        }

        string answer = "";
        for (char c: baseStr)
        {
            answer += find_least(c, mp);
        }
        return answer;
    }
};