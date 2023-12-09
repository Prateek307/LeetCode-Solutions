// link to the problem --> https://leetcode.com/problems/climbing-stairs/submissions/1115710752/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
int solve(int n,vector<int>&dp)
{
    if (n <= 2)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
        return dp[n] = solve(n-1,dp)+ solve(n-2,dp);
    
}
    int climbStairs(int n) {
    if(n<=2)
    return n;
    vector<int> dp(n+1);
    int i;
    for(i=0;i<=n;i++)
    dp[i] = -1;
    return solve(n, dp);
    }
};