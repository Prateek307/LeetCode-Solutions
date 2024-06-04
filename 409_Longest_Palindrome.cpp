// link to the problem ---> https://leetcode.com/problems/longest-palindrome

class Solution {
public:
int longestPalindrome(string s)
{
    int odd = 0;
    map<char, int> m;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
        if (m[s[i]] & 1)
            odd++;
        else
            odd--;
    }
    if (odd > 1)
        return s.length() - odd + 1;
    return s.length();
}
}
;