class Solution {
public:
    // Time: O(n), Space: O(n)
    /* vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;
        set<int> st;
        for (int& num: nums) 
        {
            freq[num]++;
            if (freq[num] > n/3) st.insert(num);
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    } */

    // Extended Boyer-Moore's Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        vector<int> temp(2);

        for (int& num: nums)
        {
            if (cnt1 == 0 && temp[1] != num)
            {
                temp[0] = num;
                cnt1++;
            }
            else if (cnt2 == 0 && temp[0] != num)
            {
                temp[1] = num;
                cnt2++;
            }
            else if (temp[0] == num)
            {
                cnt1++;
            }
            else if (temp[1] == num)
            {
                cnt2++;
            }
            else
            {
                cnt1--; cnt2--;
            }
        }

        cnt1 = 0; cnt2 = 0;
        for (int& num: nums)
        {
            if (num == temp[0]) cnt1++;
            else if (num == temp[1]) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > nums.size()/3)
        {
            ans.push_back(temp[0]);
        }
        if (cnt2 > nums.size()/3)
        {
            ans.push_back(temp[1]);
        }

        return ans;
    }
};