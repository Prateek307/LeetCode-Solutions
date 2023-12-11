// link to the prooblem ---> https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int req = (25 * n) / 100;
        int i;
        map<int, int> m;
        for (i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        int ans;
        for (auto it : m)
        {
            if (it.second > req)
            {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};