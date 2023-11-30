// link to the problem -->  https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

// code
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, n = nums.size(),max_reach = 0;
        for(i=0;i<n;i++){
            if(i>max_reach) 
            return 0;
            else
            max_reach = max(max_reach,i+nums[i]);
        } 
        return 1; 
    }
};