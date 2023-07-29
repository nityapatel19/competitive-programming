class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, n = nums.size();
        int i = 0, j = 1;
        while (j < n)
        {
            if (nums[j] == nums[i]) j++;
            else
            {
                swap(nums[j], nums[i+1]);
                i++; j++;
                k++;
            }
        }
        return k;
    }
};
