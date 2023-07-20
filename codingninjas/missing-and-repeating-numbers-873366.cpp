#include <bits/stdc++.h>

// Time: O(n), Space: O(n)
/* pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int freq[n] = {0};
    pair<int,int> ans;
    for (int &a: arr)
        freq[a-1]++;

    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0) ans.first = i+1;
        else if (freq[i] == 2) ans.second = i+1;
    }
    return ans;
} */

// Time: O(n), Space: O(1)
/* pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int S1 = 0, S2 = 0;
	for (int i = 1; i <= n; i++)
    {
        S1 += (arr[i-1] - i);
        S2 += (arr[i-1]*arr[i-1] - i*i);
    }
    return {(S2/S1 - S1)/2, (S2/S1 + S1)/2};
} */

// Time: O(n), Space: O(1). Bitwise.
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Calculate XOR(arr)^XOR(1:n) = x^y. x = repeater, y = missing.
    int x_xor_y = 0;
	for (int i = 1; i <= n; i++)
    {
        x_xor_y ^= (arr[i-1]^i);
    }

    // Find rightmost bit that is 1.
    int bit_index = 0;
    while ((x_xor_y & (1<<bit_index)) == 0) bit_index++;

    // Divide in 2 groups based on bit_index and xor them.
    int zeros = 0, ones = 0;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i-1] & (1<<bit_index)) ones ^= arr[i-1];
        else zeros ^= arr[i-1];

        if (i & (1<<bit_index)) ones ^= i;
        else zeros ^= i;
    }

    // Now, zeros and ones contain x and y, so we check which is which.
    int count = 0;
    for (int i = 0; i < n; i++) if (arr[i]==zeros) count++;

    return count == 2 ? make_pair(ones, zeros) : make_pair(zeros, ones);
}
