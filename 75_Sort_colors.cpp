// link to the problem ---> https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int one = 0, two = 0, zero = 0;
        int i, n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else if (nums[i] == 2)
                two++;
        }
        for (i = 0; i < n; i++)
        {
            if (zero > 0)
            {
                nums[i] = 0;
                zero--;
            }
            else if (one > 0)
            {
                nums[i] = 1;
                one--;
            }
            else
            {
                nums[i] = 2;
                two--;
            }
        }
    }
};