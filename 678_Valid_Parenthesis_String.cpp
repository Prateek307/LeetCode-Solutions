// link to the problem ---> https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<char> open, star;
        int i = 0;
        // for checking the validity of the closing bracket
        while (s[i] != '\0')
        {
            if (s[i] == '(')
                open.push(i);

            if (s[i] == '*')
                star.push(i);

            if (s[i] == ')')
            {
                if (!open.empty())
                {
                    open.pop();
                }
                else if (!star.empty())
                    star.pop();
                else
                    return 0;
            }
            i++;
        }
        // for checking the validity of the opening bracket
        while (!open.empty())
        {
            if (star.empty())
                return 0;

            else if (star.top() > open.top())
            {
                star.pop();
                open.pop();
            }
            else
                return 0;
        }
        return 1;
    }
};