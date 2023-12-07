// link to the problem ---> https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j  =  0;
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        if(i==s.size())
        return 1;
        return 0;
    }
};
