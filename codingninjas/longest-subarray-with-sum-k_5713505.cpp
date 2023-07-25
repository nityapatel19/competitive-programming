#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int maxlen = 0, n = nums.size();
    int sum = 0;
    map<int,int> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int target = sum-k;
        if (mp.find(target) != mp.end())
            maxlen = max(maxlen, i+1-mp[target]);
        else if (mp.find(sum) == mp.end())
            mp[sum] = i+1;
    }
    return maxlen;
}
