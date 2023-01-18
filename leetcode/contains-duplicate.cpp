class Solution {
public:
    // Slow. O(n logn)
    /*bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i-1])
                return true;
        return false;
    }*/

    // Faster. O(n)
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i=0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end())
                return true;
            else
                s.insert(nums[i]);
        }
        return false;
    }
};