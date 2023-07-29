class Solution {
public:
    /* int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0), right_max(n,0);
        for (int i = 1; i < n; i++)
        {
            left_max[i] = max(height[i-1], left_max[i-1]);
            right_max[n-1-i] = max(height[n-i], right_max[n-i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int amt = min(left_max[i], right_max[i]) - height[i];
            if (amt > 0) count += amt;
        }
        return count;
    } */

    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0, left = 0, right = height.size()-1, amt = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= left_max) left_max = height[left];
                else amt += left_max - height[left];
                left++;
            }
            else
            {
                if (height[right] >= right_max) right_max = height[right];
                else amt += right_max - height[right];
                right--;
            }
        }
        return amt;
    }
};
