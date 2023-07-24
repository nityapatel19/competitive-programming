class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        double result = 1;

        bool is_neg = n < 0;
        if (is_neg) n*=(-1);
        
        while (n > 0)
        {
            if (n%2 == 0)
            {
                x *= x;
                n/=2;
            }
            else
            {
                result *= x;
                n--;
            }
        }

        if (is_neg) result = 1 / result;

        return result;
    }
};