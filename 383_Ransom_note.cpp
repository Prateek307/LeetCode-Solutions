// link to the problem ---> https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> mp;
        for (auto it : magazine)
            mp[it]++;
        for (char i : ransomNote)
        {
            if (mp.find(i) != mp.end() && mp[i] > 0)
                mp[i]--;
            else
                return 0;
        }
        return 1;
    }
};