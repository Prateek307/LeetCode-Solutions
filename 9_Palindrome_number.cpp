// link to the problem ---> https://leetcode.com/problems/palindrome-number/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int i = 0, n = s.size();
        for (i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return 0;
        }
        return 1;
    }
};