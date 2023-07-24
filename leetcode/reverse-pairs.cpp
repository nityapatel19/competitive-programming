class Solution {
public:
    // TLE!
    /* int reversePairs(vector<int>& nums) {
        map<int,int> freq;
        int count = 0;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            for (auto& pair: freq)
            {
                if ((long)nums[i] > (long)2*pair.first) count += pair.second;
            }
            freq[nums[i]]++;
        }
        return count;
    } */

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftArr(nums.begin()+left, nums.begin()+mid+1);
        vector<int> rightArr(nums.begin()+mid+1, nums.begin()+right+1);
        int leftSize = mid+1-left, rightSize = right-mid;

        int k = left, i = 0, j = 0;
        while (i < leftSize && j < rightSize)
        {
            if (leftArr[i] <= rightArr[j]) nums[k++] = leftArr[i++];
            else nums[k++] = rightArr[j++];
        }
        while (i < leftSize) nums[k++] = leftArr[i++];
        while (j < rightSize) nums[k++] = rightArr[j++];
    }
    int countPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int i = left, j = mid+1;
        while (i <= mid && j <= right)
        {
            if (nums[i] > 2*nums[j])
            {
                count += (mid+1-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = 0;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid+1, right);
        count += countPairs(nums, left, mid, right);
        merge(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
