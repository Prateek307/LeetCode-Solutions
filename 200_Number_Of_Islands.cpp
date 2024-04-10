// link to the problem ---> https: // leetcode.com/problems/number-of-islands/

class Solution
{
public:
    void solve(vector<vector<char>> &grid, int i, int j)
    {

        int n = grid.size(), m = grid[0].size();
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        solve(grid, i - 1, j);
        solve(grid, i + 1, j);
        solve(grid, i, j - 1);
        solve(grid, i, j + 1);
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int i, j, n = grid.size(), m = grid[0].size(), cnt = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++cnt;
                    solve(grid, i, j);
                }
            }
        }
        return cnt;
    }
};