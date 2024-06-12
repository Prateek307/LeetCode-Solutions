// link to the problem --->https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int level = temp.second.second, line = temp.second.first;
            nodes[line][level].insert(node->val);
            if (node->left)
                q.push({node->left, {line - 1, level + 1}});
            if (node->right)
                q.push({node->right, {line + 1, level + 1}});
        }

        for (auto it : nodes)
        {
            vector<int> ans;
            for (auto it2 : it.second)
            {
                ans.insert(ans.end(), it2.second.begin(), it2.second.end());
            }
            res.push_back(ans);
        }

        return res;
    }
};