// link to the problem ---> https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,val = nums[nums.size()/2],res = 0;   
        for(i=0;i<nums.size();i++)
        {
            res+=abs(val-nums[i]);
        }
        return res;
    }
};