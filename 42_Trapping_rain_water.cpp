// link to the problem ---> https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), res = 0;
        if (height.size() == 1 || height.size() == 2 || is_sorted(height.begin(), height.end()))
        {
            cout << 0 << '\n';
        }
        else
        {
            vector<int> right(n), left(n);
            int i, mx = height[0];
            for (i = 0; i < n; i++)
            {
                if (mx <= height[i])
                {
                    mx = height[i];
                }
                left[i] = mx;
            }
            mx = height[n - 1];
            for (i = n - 1; i >= 0; i--)
            {
                if (mx <= height[i])
                {
                    mx = height[i];
                }
                right[i] = mx;
            }
            for (i = 0; i < n; i++)
            {
                int pole = min(left[i], right[i]);
                res += pole - height[i];
            }
        }
        return res;
    }
};