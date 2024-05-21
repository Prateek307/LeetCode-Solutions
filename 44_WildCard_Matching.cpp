// link to the problem ---> https://leetcode.com/problems/wildcard-matching/

class Solution
{
public:
    bool isMatch(string x, string y)
    {
        int n = x.size();
        int m = y.size();
        bool dy[n + 1][m + 1];
        dy[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            dy[i][0] = false;
        }
        int h = 1;
        for (int i = 1; i <= m; i++)
        {
            if (y[i - 1] == '*' and h == 1)
            {
                dy[0][i] = true;
            }
            else
            {
                dy[0][i] = false;
                h = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (x[i - 1] == y[j - 1] || y[j - 1] == '?')
                {
                    dy[i][j] = dy[i - 1][j - 1];
                }
                else if (x[i - 1] != y[j - 1] and y[j - 1] == '*')
                {
                    dy[i][j] = dy[i][j - 1] || dy[i - 1][j];
                }
                else
                {
                    dy[i][j] = false;
                }
            }
        }
        return dy[n][m];
    }
};