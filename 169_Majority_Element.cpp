// link to the problem ---> https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i , n = nums.size() , a;
        map<int , int > m;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto & it :m)
        {
            if(it.second>n/2)
            {
                a  = it.first;
            }
        }
        return a;
    }
};