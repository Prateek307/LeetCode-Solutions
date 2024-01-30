// link to the problem ---> https://leetcode.com/problems/word-break/?source=submission-noac

class Solution {
public:
    int dp[3000];
    int helper(int i , string s , set<string> &st)
    { 
        if(i==s.size())
        return 1;
        int j;
        string temp;
        if(dp[i]!=-1)
        return dp[i];
        for(j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end()) 
            {
                if(helper(j+1,s,st))
                return dp[i] =  1; 
            }
        }
        return dp[i]= 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp,-1,sizeof(dp));
        for(auto &it : wordDict)   
        {
            st.insert(it);
        }
        return helper(0,s,st);
    }
};