// link to the problem ---> https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0;
        string merged;
        while (i < word1.size() && j < word2.size())
        {
            merged.push_back(word1[i]);
            merged.push_back(word2[j]);
            i++;
            j++;
        }
        while (i < word1.size())
        {
            merged.push_back(word1[i]);
            i++;
        }
        while (j < word2.size())
        {
            merged.push_back(word2[j]);
            j++;
        }
        return merged;
    }
};