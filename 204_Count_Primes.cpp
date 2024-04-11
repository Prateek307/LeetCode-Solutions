// link to the problem ---> https://leetcode.com/problems/count-primes/description/

class Solution
{
public:
    int countPrimes(int n)
    {

        if (n <= 2)
            return 0;

        int i, limit = sqrt(n);
        vector<int> composite(n, 0);

        for (i = 2; i <= limit; i++)
        {
            if (composite[i] == 0)
            {
                for (int j = i * i; j < n; j += i)
                {
                    composite[j] = 1;
                }
            }
        }

        int cnt = 0;
        for (i = 2; i < n; i++)
        {
            if (composite[i] == 0)
                cnt++;
        }
        return cnt;
    }
};