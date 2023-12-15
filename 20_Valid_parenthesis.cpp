// link to the problem ---> https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isValid(string s)
    {
        int i = 0;
        stack<char> sk;
        while (s[i] != '\0')
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                sk.push(s[i]);
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (sk.empty())
                {
                    return 0;
                }
                if (s[i] == ')' && sk.top() == '(' || s[i] == '}' && sk.top() == '{' || s[i] == ']' && sk.top() == '[')
                    sk.pop();
                else
                {
                    return 0;
                }
            }
            i++;
        }
        if (sk.empty() == 1)
            return 1;
        else
            return 0;
    }
};