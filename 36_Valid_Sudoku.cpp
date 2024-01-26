// link to the problem ---> https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int i, j, k, n = board.size(), m = board[0].size();

        // checking for duplicate in columns
        for (j = 0; j < m; j++)
        {
            map<char, int> mp;
            for (i = 0; i < n; i++)
            {
                if (board[i][j] != '.')
                    mp[board[i][j]]++;
            }
            for (auto it : mp)
            {
                if (it.second > 1)
                    return false;
            }
        }

        // checking for duplicate in rows
        for (i = 0; i < n; i++)
        {
            map<char, int> mp;
            for (j = 0; j < m; j++)
            {
                if (board[i][j] != '.')
                    mp[board[i][j]]++;
            }
            for (auto it : mp)
            {
                if (it.second > 1)
                    return false;
            }
        }

        // checking for duplicate in 3x3 boxes
        vector<pair<int, int>> v = {
            {0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};

        for (int idx = 0; idx < 9; idx++)
        {
            int index1 = v[idx].first;
            int index2 = v[idx].second;
            map<char, int> mp;

            for (k = index1; k < index1 + 3; k++)
            {
                for (j = index2; j < index2 + 3; j++)
                {
                    if (board[k][j] != '.')
                    {
                        mp[board[k][j]]++;
                        if (mp[board[k][j]] > 1)
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};