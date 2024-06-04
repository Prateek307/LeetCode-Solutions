// link to the problem ---> https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i)
                    matrix[i][j] ^= matrix[i - 1][j];
                if (j)
                    matrix[i][j] ^= matrix[i][j - 1];
                if (i && j)
                    matrix[i][j] ^= matrix[i - 1][j - 1];
                ans.push_back(matrix[i][j]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans[ans.size() - k];
    }
};