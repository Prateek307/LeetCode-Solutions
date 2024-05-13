// link to the problem ---> https://leetcode.com/problems/integer-replacement/

class Solution
{
public:
    void Backtrack(long long n, int cnt, int &ans)
    {
        if (n == 1)
        {
            ans = min(ans, cnt);
            return;
        }
        if (n % 2 == 0)
        {
            Backtrack(n / 2, cnt + 1, ans);
        }
        else
        {
            Backtrack(n + 1, cnt + 1, ans);
            Backtrack(n - 1, cnt + 1, ans);
        }
    }
    int integerReplacement(int n)
    {
        int ans = INT_MAX;
        Backtrack(n, 0, ans);
        return ans;
    }
};
