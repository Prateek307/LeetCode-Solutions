// link to the problem ---> https://leetcode.com/problems/largest-odd-number-in-string/?envType=daily-question&envId=2023-12-07


class Solution {
public:
    string largestOddNumber(string num) {
     int i = num.size()-1;
     string s = num;
     while(i>=0)
     { 
         if(s[i]!='0' && s[i]!='2' && s[i]!='4' && s[i]!='6' && s[i]!='8' )
         break;
         i--;
     }
     string temp;
     int index = i;
     i = 0;
     while(i<=index)
     {
        temp.push_back(s[i]);
        i++;
     }
     return temp;
    }
};
