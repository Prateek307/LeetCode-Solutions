// link to the problem ---> https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int hIndex(vector<int>& citations) {
    vector<int> v = citations;
    int n = v.size();
    sort(v.begin(),v.end());
    int i,mx = 0;
    for(i=0;i<n;i++)
    {
        if(v[i] >= n - i)
        {
            mx = max(mx,n-i);
        }
    }
    return mx;
    }
};