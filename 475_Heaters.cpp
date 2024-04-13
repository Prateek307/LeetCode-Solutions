// link to the problem ---> https://leetcode.com/problems/heaters/

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {

        int i, ans = INT_MIN;
        sort(heaters.begin(), heaters.end());
        for (i = 0; i < houses.size(); i++)
        {
            int mid, low = 0, high = heaters.size() - 1, curr_radius = INT_MAX;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                curr_radius = min(curr_radius, abs(houses[i] - heaters[mid]));
                if (houses[i] == heaters[mid])
                {
                    curr_radius = 0;
                    break;
                }
                else if (houses[i] > heaters[mid])
                    low = mid + 1;
                else if (houses[i] < heaters[mid])
                    high = mid - 1;
            }
            ans = max(curr_radius, ans);
        }
        return ans;
    }
};