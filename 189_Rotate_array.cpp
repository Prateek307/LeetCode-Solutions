// link to the problem ---> https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};