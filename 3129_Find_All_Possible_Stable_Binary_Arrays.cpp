
// link to the problem ---> https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/
class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int limit, zero, one;
    int countStableArrays(int countOne, int countZero, int last)
    {
        if (countOne == one && countZero == zero)
        {
            return 1; // Found a valid arrangement
        }
        if (countOne > one || countZero > zero)
        {
            return 0; // Out of bounds
        }

        if (dp[countOne][countZero][last] != -1)
        {
            return dp[countOne][countZero][last];
        }

        int result = 0;
        if (last == 1)
        {
            // Last was 1, try to append 0s
            for (int k = 1; k <= limit && countZero + k <= zero; ++k)
            {
                result = (result + countStableArrays(countOne, countZero + k, 0)) % MOD;
            }
        }
        else
        {
            // Last was 0, try to append 1s
            for (int k = 1; k <= limit && countOne + k <= one; ++k)
            {
                result = (result + countStableArrays(countOne + k, countZero, 1)) % MOD;
            }
        }

        return dp[countOne][countZero][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit)
    {
        this->zero = zero;
        this->one = one;
        this->limit = limit;
        dp.resize(one + 1, vector<vector<int>>(zero + 1, vector<int>(2, -1)));
        int result = 0;
        result = (result + countStableArrays(0, 0, 1)) % MOD; // Start with 1
        result = (result + countStableArrays(0, 0, 0)) % MOD; // Start with 0

        return result;
    }
};