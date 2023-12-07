
// link to the problem ---> https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06

class Solution
{
public:
    int totalMoney(int n)
    {
        int ans = 0;
        if (n >= 8)
        {
            int quo = n / 7;
            int i;
            int sum_of_seven_terms = 28;
            for (i = 0; i < quo; i++)
            {
                ans = ans + sum_of_seven_terms + (i * 7);
            }
            int start = quo + 1;
            int rem = n % 7;
            for (i = 0; i < rem; i++)
            {
                ans += start;
                start++;
            }
            return ans;
        }
        else
        {
            return n * (n + 1) / 2;
        }
    }
};