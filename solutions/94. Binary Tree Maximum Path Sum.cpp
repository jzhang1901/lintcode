/* 94. Binary Tree Maximum Path Sum
Description

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.
Have you met this question in a real interview?  
Example

Given the below binary tree:

  1
 / \
2   3

return 6.
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
    struct ResultType {
        int singlePath; // from root to leaf , is not necessary including root
        int maxPath;
        ResultType(int singlePath, int maxPath) :
            singlePath(singlePath),
            maxPath(maxPath) {};
        ~ResultType() {};
    };
    
    ResultType maxPathSumHelper(TreeNode *root) {
        if(!root) return ResultType(0, INT_MIN);

        ResultType left = maxPathSumHelper(root->left);
        ResultType right = maxPathSumHelper(root->right);
        
        int singlePath = root->val + max(left.singlePath, right.singlePath);
        singlePath = max(0, singlePath);　//这里很重要，可以保证有可能不取root

        
        int maxPath = max(left.maxPath, right.maxPath);
        //left.singlePath　是从左边儿子节点出发的往下走的最大路径，里面可能什么节点也不包含

        maxPath = max(maxPath, root->val + left.singlePath + right.singlePath);
        return ResultType(singlePath, maxPath);
    }
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        return maxPathSumHelper(root).maxPath;
    }
};