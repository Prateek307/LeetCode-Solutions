// link to the problem ---> https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150


#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&v , int n , int index,vector<int> &dp)
{
    if(index==n-1)
    {
        return 0;
    }

    if(index>=n)
    return 1e8;

    if(dp[index]!=-1)
    return dp[index];

    int ans = 1e8,i;
    for(i=index+1;i<=index+v[index];i++)
    {
        ans = min(ans,solve(v,n,i,dp)+1);
    }
    return dp[index] = ans;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n),dp(100000);
    int i;
    for(i=0;i<100000;i++)
    dp[i] = -1;
    for(i=0;i<n;i++)
    cin>>v[i];
    cout<<solve(v,n,0,dp)<<'\n';
    return 0; 
}