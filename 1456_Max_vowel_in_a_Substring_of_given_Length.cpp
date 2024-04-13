// link to the problem ---> https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool isVowel(char letter)
    {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            return 1;
        return 0;
    }
    int maxVowels(string s, int k)
    {
        // we are going to use sliding window technique

        int i, vowelCnt = 0;
        for (i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                vowelCnt++;
        }

        int ans = INT_MIN, n = s.size(), prev;
        ans = max(ans, vowelCnt);
        prev = 0;
        while (i < n)
        {
            if (isVowel(s[prev]))
                vowelCnt--;
            prev++;
            if (isVowel(s[i]))
                vowelCnt++;
            ans = max(ans, vowelCnt);
            i++;
        }

        return ans;
    }
};