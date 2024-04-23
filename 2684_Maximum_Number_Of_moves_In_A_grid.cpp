// link to the problem ---> https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

class Solution
{
public:
    int solve(int row, int col, int n, int m, vector<vector<int>> &grid,
              vector<vector<int>> &dp)
    {
        if (row >= n || col >= m)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int move = 0;
        if (row - 1 >= 0 && col + 1 < m &&
            grid[row - 1][col + 1] > grid[row][col])
        {
            move = 1 + solve(row - 1, col + 1, n, m, grid, dp);
        }
        if (col + 1 < m && grid[row][col + 1] > grid[row][col])
        {
            move = max(move, 1 + solve(row, col + 1, n, m, grid, dp));
        }
        if (row + 1 < n && col + 1 < m &&
            grid[row + 1][col + 1] > grid[row][col])
        {
            move = max(move, 1 + solve(row + 1, col + 1, n, m, grid, dp));
        }
        return dp[row][col] = move;
    }
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int max_moves = 0;
        for (int i = 0; i < n; ++i)
        {
            max_moves = max(max_moves, solve(i, 0, n, m, grid, dp));
        }
        return max_moves;
    }
};