// link to the problem ---> https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

// we code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    map<int,int> m;
    int i;
    for(i=0;i<nums.size();i++)
    {
        m[nums[i]]++;
    }
    for(auto it = nums.begin();it!=nums.end();)
    {
        if(m[*it]>2)
        {
            m[*it]--;
            it = nums.erase(it);
        }
        else
        {
            ++it;
        }
    }
    return nums.size();
    }
};