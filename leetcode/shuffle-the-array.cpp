class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer(n*2);
        for (int i = 0; i < n; i++)
        {
            answer[i*2] = nums[i];
            answer[i*2+1] = nums[n+i];
        }
        return answer;
    }
};
