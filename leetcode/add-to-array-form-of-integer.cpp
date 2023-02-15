class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int idx = num.size() - 1;
        int carry = 0;
        while (k > 0 || idx >= 0 || carry > 0)
        {
            int last_digit = k%10;
            k /= 10;
            int sum = last_digit + carry;
            if (idx >= 0) sum += num[idx--];
            ans.push_back(sum%10);
            carry = sum / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
