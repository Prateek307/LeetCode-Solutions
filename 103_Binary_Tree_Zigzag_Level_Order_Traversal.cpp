// link to the problem ---> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> res;
        bool leftToRight = 1;
        if (root == NULL)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int i, size = q.size();
            vector<int> ans(size);
            for (i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int index = leftToRight ? i : size - i - 1;
                ans[index] = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            leftToRight = !leftToRight;
            res.push_back(ans);
        }
        return res;
    }
};