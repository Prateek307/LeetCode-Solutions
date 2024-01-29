// link to the problem ---> https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size(), low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                high = mid - 1;
            else if (mid < n - 1 && nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                break;
        }
        return mid;
    }
};