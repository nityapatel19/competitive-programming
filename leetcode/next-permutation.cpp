class Solution {
public:
    // Inbuilt STL function
    /* void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    } */

    // Can be optimized a little.
    /* void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int k;
        for (k = n-2; k >= 0; k--)
        {
            if (nums[k] < nums[k+1])
                break;
        }

        // If nums is in decreasing order
        if (k == -1)
        {
            // Return ascending order
            sort(nums.begin(), nums.end());
        }
        else
        {
            int next_greatest_idx = k+1;
            for (int i = k+2; i < n; i++)
            {
                if (nums[i] > nums[k] && nums[i]-nums[k] < nums[next_greatest_idx]-nums[k])
                {
                    next_greatest_idx = i;
                }
            }
            swap(nums[k], nums[next_greatest_idx]);
            
            // Sort the remaining
            sort(nums.begin()+k+1, nums.end());
        }
    } */

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int k;
        for (k = n-2; k >= 0; k--)
        {
            if (nums[k] < nums[k+1])
                break;
        }

        // If nums is in decreasing order
        if (k == -1)
        {
            // Return ascending order (using reverse in this case to save time)
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // This loop will keep the remaining elements in descending order and swap nums[k] with next greatest number.
            for (int i = n-1; i > k; i--)
            {
                if (nums[i] > nums[k])
                {
                    swap(nums[i], nums[k]);
                    break;
                }
            }
            
            // Sort the remaining using reverse
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};