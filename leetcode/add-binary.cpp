class Solution {
public:
    // Slow, long, readable but redundant.
    /*string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        int a_idx = a.length()-1, b_idx = b.length()-1;
        for (; a_idx>=0 && b_idx>=0; a_idx--, b_idx--)
        {
            if (a[a_idx]=='1' && b[b_idx]=='1')
            {
                if (carry)
                {
                    res = '1' + res;
                }
                else
                {
                    res = '0' + res;
                    carry = true;
                }
            }
            else if (a[a_idx]=='1' || b[b_idx]=='1')
            {
                if (carry)
                {
                    res = '0' + res;
                }
                else
                {
                    res = '1' + res;
                }
            }
            else
            {
                if (carry)
                {
                    res = '1' + res;
                    carry = false;
                }
                else
                {
                    res = '0' + res;
                }
            }          
        }
        while (a_idx >= 0)
        {
            if (carry && a[a_idx] == '1')
            {
                res = '0' + res;
            }
            else if (carry || a[a_idx] == '1')
            {
                res = '1' + res;
                carry = false;
            }
            else
            {
                res = '0' + res;
            }
            a_idx--;
        }
        while (b_idx >= 0)
        {
            if (carry && b[b_idx] == '1')
            {
                res = '0' + res;
            }
            else if (carry || b[b_idx] == '1')
            {
                res = '1' + res;
                carry = false;
            }
            else
            {
                res = '0' + res;
            }
            b_idx--;
        }
        if (carry) res = "1" + res;
        return res;
    }*/

    // Much better.
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int a_idx = a.length()-1, b_idx = b.length()-1;
        while (a_idx >= 0 || b_idx >= 0 || carry)
        {
            if (a_idx >= 0) carry += a[a_idx--] - '0';
            if (b_idx >= 0) carry += b[b_idx--] - '0';

            ans += '0' + carry%2;
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};