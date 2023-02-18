#include <iostream>
#include <vector>
#include <cmath>

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
    int _minDiff = INT32_MAX;
    int _prevVal;
public:
    // Knowing that the inorder traversal of a BST outputs sorted (non-decreasing)
    // values, I can simply keep track of the previous value in the traversal,
    // comparing the difference between its value minus the current node's value
    // to the previous minimum difference.
    int bstMinAbsDiff(TreeNode* root)
    {
        _prevVal = root->val;
        _recurse(root);
        return _minDiff;
    }

    void _recurse(TreeNode* node)
    {
        if (node == nullptr)
            return;
        
        _recurse(node->left);
        
        if (std::abs(node->val - _prevVal) < _minDiff)
            _minDiff = std::abs(node->val - _prevVal);
        
        _prevVal = node->val;

        _recurse(node->right);
    }

    // using a vector to store the inorder traversal of the tree, and
    // calculating the min absolute difference by traversing the vector.
    // EXTREMELY memory inefficient
    int bstMinDifference(TreeNode *node)
    {
        std::vector<int> inorder;
        bstInorderVector(node, inorder);

        int prev_val = inorder[0];
        int min_diff = INT32_MAX;

        for (size_t i = 1; i < inorder.size(); ++i)
        {
            int abs_diff = std::abs(inorder[i] - prev_val);

            if (abs_diff < min_diff)
                min_diff = abs_diff;

            prev_val = inorder[i];
        }

        return min_diff;
    }

    void bstInorderVector(TreeNode *node, std::vector<int> &node_vals)
    {
        if (node == nullptr)
            return;
        
        bstInorderVector(node->left, node_vals);
        node_vals.push_back(node->val);
        bstInorderVector(node->right, node_vals);
    }
};

int main()
{
    Solution s;

    // Root
    TreeNode *root = new TreeNode(4);
    
    // Level 1
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    // Level 2
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << s.bstMinAbsDiff(root) << '\n';
}