// link to the problem ---> https://leetcode.com/problems/power-of-four/

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 0)
            return 0;
        if (__builtin_popcount(n) == 1)
        {
            int val = floor(log2(n) + 1);
            if (val & 1)
                return 1;
            return 0;
        }
        return 0;
    }
};