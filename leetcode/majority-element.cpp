class Solution {
public:
    // Use Boyer-Moore Majority Voting Algorithm
    // It gives the best candidate to be majority in O(1) space.
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], count = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == majority) count++;
            else count--;

            if (count == 0)
            {
                majority = nums[i];
                count = 1;
            }
        }
        // As we know majority element exists, we don't need to verify.
        return majority;
    }
};