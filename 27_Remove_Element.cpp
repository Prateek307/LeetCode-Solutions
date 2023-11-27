// link to the problem --->   https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, val;
    cin >> n >> val;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int cnt = 0;
    for (auto it = v.begin(); it != v.end();)
    {
        if(*it==val)
        { 
            it = v.erase(it);
        }
        else
        {
            cnt++;
            ++it;
        }
    }
    for (auto it : v)
    {
        cout << it << ' ';
    }
    cout << '\n';
    cout<<cnt<<'\n';
    return 0;
}