class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        bool is_zero = false;
        long long count = 0;
        long long answer = 0;
        for (int num: nums)
        {
            if (is_zero && num==0)
            {
                count++;
            }
            else if (is_zero && num!=0)
            {
                is_zero = false;
                answer += ((count)*(count+1))/2;
                count = 0;
            }
            else if (num==0) // equivalent to (!is_zero && num==0)
            {
                is_zero = true;
                count++;
            }
        }
        if (is_zero) answer += ((count)*(count+1))/2;
        return answer;
    }
};
