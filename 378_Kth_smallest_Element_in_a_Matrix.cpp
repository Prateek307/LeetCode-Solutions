// link to the problem ---> https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/1234844952/

#include <vector>

class Solution
{
public:
    int countLessEqual(const std::vector<std::vector<int>> &matrix, int target)
    {
        int count = 0;
        int n = matrix.size();
        int i = n - 1; // Start from bottom-left corner
        int j = 0;

        while (i >= 0 && j < n)
        {
            if (matrix[i][j] <= target)
            {
                count += i + 1; // Add the entire column
                j++;            // Move to the next column
            }
            else
            {
                i--; // Move to the previous row
            }
        }

        return count;
    }

    int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};