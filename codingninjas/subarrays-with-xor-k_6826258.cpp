#include <bits/stdc++.h>

int subarraysWithSumK(vector<int> a, int b) {
    // Write your code here
    map<int,int> mp; // Stores number of ways i is formed by prefix xor.
    mp[0] = 1;
    int n = a.size(), count = 0;
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr^a[i];
        int target = xr^b;
        if (mp.find(target) != mp.end()) count += mp[target];
        mp[xr]++;
    }
    return count;
}
/* 
  1 2 3 3

0->1
1->1
3->1
 */