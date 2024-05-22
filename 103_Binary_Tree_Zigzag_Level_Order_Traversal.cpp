// link to the problem ---> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void zigzagLevelOrder(TreeNode *root, vector<vector<int>> &ans)
    {
        stack<TreeNode *> mainS;
        stack<TreeNode *> childS;
        mainS.push(root);
        int level = 1;
        vector<int> subAns;
        while (mainS.size() > 0)
        {
            TreeNode *front = mainS.top();
            mainS.pop(); // remove
            subAns.push_back(front->val);
            if (level % 2 == 1)
            { // add
                if (front->left != NULL)
                {
                    childS.push(front->left);
                }
                if (front->right != NULL)
                {
                    childS.push(front->right);
                }
            }

            if (level % 2 == 0)
            {
                if (front->right != NULL)
                {
                    childS.push(front->right);
                }
                if (front->left != NULL)
                {
                    childS.push(front->left);
                }
            }

            if (mainS.size() == 0)
            {
                swap(childS, mainS);
                ans.push_back(subAns);
                subAns.clear();
                level++;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        zigzagLevelOrder(root, ans);
        return ans;
    }
};