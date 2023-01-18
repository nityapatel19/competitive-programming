class Solution {
public:
    // Uses division.
    /*vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int nums_zeros = 0, idx = 0;
        bool flag = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) nums_zeros++;
            if (nums_zeros == 1 && flag) {flag = false; idx = i; continue;}
            prod *= nums[i];
        }
        vector<int> ans(nums.size());
        if (nums_zeros > 1)
        {
            fill (ans.begin(), ans.end(), 0);
        }
        else if (nums_zeros == 1)
        {
            fill (ans.begin(), ans.end(), 0);
            ans[idx] = prod;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }*/

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix_prod[n], postfix_prod[n];
        prefix_prod[0] = 1;
        postfix_prod[n-1] = 1;

        for (int i = 1; i < n; ++i)
        {
            prefix_prod[i] = prefix_prod[i-1] * nums[i-1];
            postfix_prod[n-i-1] = postfix_prod[n-i] * nums[n-i];
        }

        vector<int> answer(n);
        for (int i = 0; i < n; ++i)
        {
            answer[i] = prefix_prod[i] * postfix_prod[i];
        }

        return answer;
    }
};