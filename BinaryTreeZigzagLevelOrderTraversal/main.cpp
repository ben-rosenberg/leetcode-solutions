#include <iostream>
#include <vector>


struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int val)
        : val(val), left(nullptr), right(nullptr) {}

    TreeNode(int val, TreeNode *left, TreeNode *right)
        : val(val), left(left), right(right) {}
};

/**
 * @brief Given the root of a binary tree, return the zigzag level order
 * traversal of the tree's nodes.
 * 
 * At each level, traversal should alternate between left-to-right and right-
 * to-left. Each inner vector in the output represents one level in the tree.
 */
class Solution {
public:
    /**
     * @brief Returns the zigzag level order traversal of a binary tree in a
     * vector of vectors.
     * 
     * Faster than 100% of submissions.
     * Less memory than 79% of submissions.
     * 
     * @param root The root of the binary tree
     * @return std::vector<std::vector<int>> 
     */
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        int const tree_height = getTreeHeight(root);
        std::vector<std::vector<int>> level_order_node_vals(tree_height, std::vector<int>());

        for (int level = 0; level < tree_height; ++level)
            _currentLevelZigzag(root, level_order_node_vals, level, level);
        
        return level_order_node_vals;
    }

private:
    void _currentLevelZigzag(TreeNode *node, std::vector<std::vector<int>> &out, int level, int const out_idx)
    {
        if (node == nullptr)
            return;
        
        if (level == 0) {
            out[out_idx].push_back(node->val);
            return;
        }

        if (out_idx % 2 == 0) {
            _currentLevelZigzag(node->left, out, level - 1, out_idx);
            _currentLevelZigzag(node->right, out, level - 1, out_idx);
        } else {
            _currentLevelZigzag(node->right, out, level - 1, out_idx);
            _currentLevelZigzag(node->left, out, level - 1, out_idx);
        }
    }

    int getTreeHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        
        int left_subtree_height = getTreeHeight(node->left);
        int right_subtree_height = getTreeHeight(node->right);

        return left_subtree_height > right_subtree_height
            ? left_subtree_height + 1
            : right_subtree_height + 1;
    }
};

static void printTraversal(std::vector<std::vector<int>> &nodes)
{
    for (const auto &level : nodes)
    {
        std::cout << "{ ";
        for (const auto &node_val : level)
        {
            std::cout << node_val << ", ";
        }

        std::cout << "}\n";
    }
}

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(3, 
        new TreeNode(9), new TreeNode(20,
        new TreeNode(15), new TreeNode(7)));

    auto level_order = s.zigzagLevelOrder(root);
    printTraversal(level_order);
}