// link to the problem ---> https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int i = 0 , cnt = 0;
        while(i<s.size() && s[i]==' ')
        i++;
        while(i<s.size() && s[i]!=' ')
        {
            cnt++;
            i++;
        }
        return cnt;
    }
};