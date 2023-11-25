/*Link to the problem*/
// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i , n = nums.size();
        map<int , int> m;
        vector<int> v;
        for(i=0;i<n;i++)
        {
             if(m.count(target-nums[i])>0)
             {
                 v.push_back(i);
                 v.push_back(m[target-nums[i]]);
                 break;
             }
             else
             m[nums[i]] = i;
        }
        return v;
    }
};