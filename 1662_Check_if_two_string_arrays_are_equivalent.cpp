// link to the problem ---> https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/?envType=daily-question&envId=2023-12-01


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i  = 0;
        string temp1 = word1[0],temp2 = word2[0];
        i++;
        while(i<word1.size() && i<word2.size())
        { 
            temp1+=word1[i];
            temp2+=word2[i];
            i++;
        }
        while(i<word1.size())
        {
            temp1+=word1[i];
            i++;
        }
        while(i<word2.size())
        {
            temp2+=word2[i];
            i++;
        }
        if(temp1==temp2)
        return 1;
        return 0;
    }
};