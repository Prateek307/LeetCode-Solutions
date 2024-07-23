// link to the problem ---> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int p = 0, i = 0;
        return build(preorder, inorder, p, i, INT_MAX);
    }

private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &p, int &i, int stop)
    {
        if (i < inorder.size() && inorder[i] != stop)
        {
            TreeNode *root = new TreeNode(preorder[p++]);
            root->left = build(preorder, inorder, p, i, root->val);
            i++;
            root->right = build(preorder, inorder, p, i, stop);
            return root;
        }
        return nullptr;
    }
};