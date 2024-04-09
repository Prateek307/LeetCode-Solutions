// link to the problem ---> https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        int sign = 1;
        while (i < n && s[i] == ' ')
            i++;

        long ans = 0;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }

        else if (s[i] == '+')
        {
            sign = 1;
            i++;
        }

        while (i < n)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;
            }
            else
                return (ans * sign);
        }
        return (ans * sign);
    }
};