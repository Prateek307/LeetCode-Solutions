// link to the problem ---> https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> mypair = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        int i;
        string ans = "";
        for (i = 0; i < mypair.size(); i++)
        {
            while (num >= mypair[i].first)
            {
                ans += mypair[i].second;
                num -= mypair[i].first;
            }
        }
        return ans;
    }
};