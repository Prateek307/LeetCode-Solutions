// link to the problem ---> https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
  vector<int> generateRows(int row)
  {
    int col;
    vector<int> ans;
    int val = 1;
    ans.push_back(1);
    for (col = 1; col < row; col++)
    {
      val = val * (row - col);
      val = val / col;
      ans.push_back(val);
    }
    return ans;
  }

  vector<vector<int>> generate(int numRows)
  {
    if (numRows == 1)
      return {{1}};
    else if (numRows == 2)
    {
      return {{1}, {1, 1}};
    }
    int i;
    vector<vector<int>> res;
    for (i = 1; i <= numRows; i++)
    {
      res.push_back(generateRows(i));
    }
    return res;
  }
};