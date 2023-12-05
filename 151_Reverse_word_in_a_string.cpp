// link to the problem --->https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150


#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    vector<string> ans;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        string temp;
        while (s[i] != ' ' && i < s.size())
        {
            temp.push_back(s[i]);
            i++;
        }
        ans.push_back(temp);
        i++;
    }
    reverse(ans.begin(), ans.end());
    string mystring = "";
    i = 0;
    while (i < ans.size())
    {
        mystring += ans[i];
        i++;
        if (i == ans.size())
            break;
        mystring += " ";
    }
    for (auto it : mystring)
        cout << it;
}