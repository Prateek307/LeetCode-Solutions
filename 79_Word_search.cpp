// link to the problem --->https://leetcode.com/problems/word-search/

class Solution
{
public:
    bool search_in_board(int i, int j, vector<vector<char>> &board, string word,
                         int index)
    {
        if (index == word.size())
            return true;

        int n = board.size(), m = board[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '*'; // Mark visited

        bool found = search_in_board(i - 1, j, board, word, index + 1) ||
                     search_in_board(i + 1, j, board, word, index + 1) ||
                     search_in_board(i, j - 1, board, word, index + 1) ||
                     search_in_board(i, j + 1, board, word, index + 1);

        board[i][j] = temp; // Restore the character
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] &&
                    search_in_board(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};