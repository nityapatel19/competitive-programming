class Solution {
public:
    /* 
    Dutch National Flag Algorithm:
    Good explanation: https://www.youtube.com/watch?v=tp8JIuCXBaU

    Use 3 pointers, left, right and i.
    Think as if left is to store 0s and move,
    right is to store 2s and move,
    i is the current pointer.
    In the end, 0s will be on left, 2s on right, leaving 1s in the middle.
    */
    void sortColors(vector<int>& nums) {
        int i = 0, left = 0, right = nums.size()-1;

        while (i <= right)
            if (nums[i] == 0) swap(nums[left++], nums[i++]);
            else if (nums[i] == 2) swap(nums[right--], nums[i]);
            else i++;
    }
};