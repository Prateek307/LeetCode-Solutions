// link to the problem ---> https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector<int> v1,v2,v3,v4;
    int ones_cnt = 0 , zeros_cnt = 0;
    int i,j , n = grid.size() , m = grid[0].size();
    for(i=0;i<n;i++)
    {
        ones_cnt = 0;
        zeros_cnt = 0;
        for(j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            ones_cnt++;
            else
            zeros_cnt++;
        }
        v1.push_back(ones_cnt);
        v2.push_back(zeros_cnt);
    }
    for(j=0;j<m;j++)
    {
        ones_cnt = 0;
        zeros_cnt = 0;
        for(i=0;i<n;i++)
        {
            if(grid[i][j]==1)
            ones_cnt++;
            else
            zeros_cnt++;
        }
        v3.push_back(ones_cnt);
        v4.push_back(zeros_cnt);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            grid[i][j] = (v1[i]+v3[j])-(v2[i]+v4[j]);
        }
    }   
    return grid;
    }
};