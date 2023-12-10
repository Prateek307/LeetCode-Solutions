// link to the problem --> https://leetcode.com/problems/transpose-matrix/?envType=daily-question&envId=2023-12-10

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> v(m,vector<int>(n));
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                v[i][j] = matrix[j][i];
            }
        }
        return v;
    }
};