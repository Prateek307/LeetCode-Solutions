// link to the problem ---> https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2023-12-13

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       vector<int> ans;
    int cnt , i, j ,n = mat.size() , m = mat[0].size();
    for (i = 0; i < n; i++)
    {
        cnt = 0;
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                cnt++;
        }
        if (cnt == 1)
        {
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    ans.push_back(j);
                }
            }
        }
    }
    int res = 0;
    for(j=0;j<ans.size();j++)
    {
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(mat[i][ans[j]]==1)
            cnt++;
        }
        if(cnt==1)
        res++;
    } 
    return res;
    }
};