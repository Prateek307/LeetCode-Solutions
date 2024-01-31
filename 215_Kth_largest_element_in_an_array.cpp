// link to the problem ---> https://leetcode.com/problems/kth-largest-element-in-an-array/

 class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int i;
        multiset<int, greater<int>> st;
        for (i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        int cnt = 0, ans = 0;
        for (auto it : st)
        {
            ans = it;
            if (cnt == k - 1)
                break;
            cnt++;
            it++;
        }
        return ans;
    }
};