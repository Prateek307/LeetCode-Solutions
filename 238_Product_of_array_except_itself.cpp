// link to the problem ---> https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n) , rightSum(n) , v , ans;
        v = nums;
    int i;
    rightSum[0] = v[0];
    for(i=1;i<n;i++)
    {
        rightSum[i] = rightSum[i-1]*v[i];
    }

    leftSum[n-1] = v[n-1];
    for(i=n-2;i>=0;i--)
    {
        leftSum[i] = leftSum[i+1]*v[i];
    }
    
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            ans.push_back(rightSum[n-2]);
        }
        else if(i==0)
        {
            ans.push_back(leftSum[1]);
        }
        else
        ans.push_back(leftSum[i+1]*rightSum[i-1]);
    }
    return ans;
    }
};