// link to the problem ---> https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=study-plan-v2&envId=leetcode-75

#include <string>
#include <unordered_map>

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Check if the two strings have the same characters
        unordered_map<char, int> freq1, freq2;
        for (char ch : word1)
        {
            freq1[ch]++;
        }
        for (char ch : word2)
        {
            freq2[ch]++;
            // If any character in word2 is not in word1, return false
            if (freq1.find(ch) == freq1.end())
            {
                return false;
            }
        }
        // Check if the frequency of characters is the same
        unordered_map<int, int> count1, count2;
        for (auto &entry : freq1)
        {
            count1[entry.second]++;
        }
        for (auto &entry : freq2)
        {
            count2[entry.second]++;
        }
        // If the frequency of frequencies is different, return false
        if (count1 != count2)
        {
            return false;
        }
        return true;
    }
};
