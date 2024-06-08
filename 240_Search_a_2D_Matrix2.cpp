// link to the problem ---> https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowindex = 0;
        int colindex = col - 1;

        while (rowindex < row && colindex >= 0)
        {
            int element = matrix[rowindex][colindex];
            if (target == element)
            {
                return 1;
            }
            if (target > element)
            {
                rowindex++;
            }
            else
            {
                colindex--;
            }
        }
        return 0;
    }
};