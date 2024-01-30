// link to the problem ---> https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid, n = nums.size(), low = 0, high = n - 1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            // move in the left part
            else if (nums[mid] >= nums[low])
            {
                if (target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // move in the right part
            else
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};