class Solution {
public:
    /* void helper(string& s, int idx, vector<string>& perms, int n) {
        if (idx == n)
        {
            perms.push_back(s);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            swap(s[i], s[idx]);
            helper(s,idx+1, perms, n);
            swap(s[i], s[idx]);
        }
    }
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++)
        {
            s += ('0'+i);
        }
        vector<string> perms;
        helper(s, 0, perms, n);
        sort(perms.begin(), perms.end());

        return perms[k-1];
    } */

    string getPermutation(int n, int k) {
        string s = "";
        // n-1 factorial.
        int factorial = 1, digit, digit_idx;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {
            factorial *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        k = k-1; // 0-based indexing is better
        while (true)
        {
            digit_idx = k / factorial;
            digit = nums[digit_idx];
            s += ('0'+digit);
            nums.erase(nums.begin() + digit_idx);

            if (nums.size() == 0) break;

            k %= factorial;
            factorial /= nums.size();
        }
        
        return s;
    }
};
