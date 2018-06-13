/*475. Binary Tree Maximum Path Sum II

Description

Given a binary tree, find the maximum path sum from root.

The path may end at any node in the tree and contain at least one node in it.
Have you met this question in a real interview?  
Example

Given the below binary tree:

  1
 / \
2   3

return 4. (1->3)
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        if(!root) return 0;
        int left = maxPathSum2(root->left);
        int right = maxPathSum2(root->right);
        int maxSum = root->val;
        maxSum = max(maxSum, root->val + left);
        maxSum = max(maxSum, root->val + right);
        return maxSum;
    }
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        if(!root) return 0;
        int left = maxPathSum2(root->left);
        int right = maxPathSum2(root->right);
        return root->val + max(0, max(left, right)); //这里左右的最大再和０比较可以保证有机会不取左右节点
    }
};