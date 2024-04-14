// link to the problem ---> https://leetcode.com/problems/reverse-integer/description/

class Solution
{
public:
    int reverse(int x)
    {
        long long reversed = 0; // Use long long to handle potential overflow

        while (x != 0)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Check for overflow
        if (reversed < INT_MIN || reversed > INT_MAX)
        {
            return 0;
        }

        return static_cast<int>(reversed);
    }
};
