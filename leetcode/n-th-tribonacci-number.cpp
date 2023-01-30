class Solution {
public:
    int tribonacci(int n) {
        if (n < 1) return 0;
        if (n < 3) return 1;
        
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++)
        {
            temp = a+b+c;
            a = b;
            b = c;
            c = temp;

            // OR
            /*
            c = a+b+c;
            b = c - a - b;
            a = c - a - b;
            */
        }
        return c;
    }
};