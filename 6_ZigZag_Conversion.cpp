// link to the problem ---> https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows)
        {
            return s;
        }

        vector<string> ans(numRows);
        int i = 0;
        bool goingDown = false;

        for (char ch : s)
        {
            ans[i] += ch;
            if (i == 0 || i == numRows - 1)
            {
                goingDown = !goingDown;
            }
            i += goingDown ? 1 : -1;
        }

        string result = "";
        for (const string &row : ans)
        {
            result += row;
        }

        return result;
    }
};