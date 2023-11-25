/*Link to the problem*/
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/



class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int n,lastg = -1 , lastp = -1 , lastm = -1;
    n = garbage.size();
    int i, total_pick_time = 0;
    for(i=0;i<n;i++)
    {
        string s;
        s = garbage[i];
        int j = 0;
        while(j<s.size())
        {
            if(s[j]=='G')
            lastg = i;
            else if(s[j]=='P')
            lastp = i;
            else
            lastm = i;
            j++;
        }
        total_pick_time+=s.size();
    }   
    int g_count = 0 , m_count = 0 , p_count = 0;
    int ans = 0;
    for(i=1;i<n;i++)
    {
        if(i<=lastm)
        {
            ans+=travel[i-1];
        }
        if(i<=lastp)
        {
            ans+=travel[i-1];
        }
        if(i<=lastg)
        {
            ans+=travel[i-1];
        }
    }
    return total_pick_time+ans;  
    }
};