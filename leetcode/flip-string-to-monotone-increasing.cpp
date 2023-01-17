class Solution {
public:
    // Weird solution, think about it.
    /*
        00110001010011
              i
        when at index i,
        if it is '1', increase the count of 1's.
        If it is zero, min_count = min(count_ones, min_count+1);
        We either flip all the ones before it,
        or do min_count and flip the current bit.
    */
    int minFlipsMonoIncr(string s) {
        int count_ones = 0, min_flips = 0;
        for (char c: s)
        {
            if (c == '1')
            {
                count_ones++;
            }
            else
            {
                min_flips = min(count_ones, min_flips+1);
            }
        }
        return min_flips;
    }
};