// link to the problem ---> https://leetcode.com/problems/unique-binary-search-trees-ii/description/

class Solution
{
public:
    // Function to generate all possible binary search trees (BSTs) from values ranging from 'st' to 'e'
    vector<TreeNode *> allPossibleBSTs(int st, int e)
    {
        // Base cases: if the start index exceeds the end index, return a vector containing NULL
        if (st > e)
            return {NULL};
        // If the start index equals the end index, return a vector containing a single node with value 'st'
        if (st == e)
            return {new TreeNode(st)};

        vector<TreeNode *> ans; // Vector to store the generated BSTs
        // Iterate through each value from 'st' to 'e'
        for (int i = st; i <= e; i++)
        {
            // Generate all possible left subtrees from values ranging from 'st' to 'i-1'
            vector<TreeNode *> left = allPossibleBSTs(st, i - 1);
            // Generate all possible right subtrees from values ranging from 'i+1' to 'e'
            vector<TreeNode *> right = allPossibleBSTs(i + 1, e);

            // Construct BSTs by combining each left subtree with each right subtree
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i); // Create a new node with value 'i'
                    root->left = left[j];             // Set the left subtree
                    root->right = right[k];           // Set the right subtree
                    ans.push_back(root);              // Add the constructed BST to the result vector
                }
            }
        }

        return ans; // Return the vector containing all possible BSTs
    }

    // Function to generate all possible BSTs using memoization
    vector<TreeNode *> allPossibleBSTsUsingMem(int st, int e, map<pair<int, int>, vector<TreeNode *>> &dp)
    {
        // Base cases: if the start index exceeds the end index, return a vector containing NULL
        if (st > e)
            return {NULL};
        // If the start index equals the end index, return a vector containing a single node with value 'st'
        if (st == e)
            return {new TreeNode(st)};

        // If the result for the current range is already computed, return it from the memoization table
        if (dp.find({st, e}) != dp.end())
            return dp[{st, e}];

        vector<TreeNode *> ans; // Vector to store the generated BSTs
        // Iterate through each value from 'st' to 'e'
        for (int i = st; i <= e; i++)
        {
            // Generate all possible left subtrees from values ranging from 'st' to 'i-1'
            vector<TreeNode *> left = allPossibleBSTsUsingMem(st, i - 1, dp);
            // Generate all possible right subtrees from values ranging from 'i+1' to 'e'
            vector<TreeNode *> right = allPossibleBSTsUsingMem(i + 1, e, dp);

            // Construct BSTs by combining each left subtree with each right subtree
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i); // Create a new node with value 'i'
                    root->left = left[j];             // Set the left subtree
                    root->right = right[k];           // Set the right subtree
                    ans.push_back(root);              // Add the constructed BST to the result vector
                }
            }
        }

        // Memoize the result for the current range
        return dp[{st, e}] = ans;
    }

    // Function to generate all possible BSTs of values from 1 to n
    vector<TreeNode *> generateTrees(int n)
    {
        // Uncomment one of the following lines based on the approach you want to use

        // Approach 1: Without memoization
        // return allPossibleBSTs(1, n);

        // Approach 2: With memoization
        map<pair<int, int>, vector<TreeNode *>> dp; // Memoization table
        return allPossibleBSTsUsingMem(1, n, dp);
    }
};
