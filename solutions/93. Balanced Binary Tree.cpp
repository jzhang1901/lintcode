/*93. Balanced Binary Tree

Description

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Have you met this question in a real interview?  
Example

Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7

The binary tree A is a height-balanced binary tree, but B is not.

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
// Divide and Conquer
class Solution {
public:
    struct ResultType {
        bool is_balanced;
        int max_depth;
        ResultType(bool is_balanced, int max_depth) : 
        is_balanced(is_balanced), max_depth(max_depth) {};
        ~ResultType() {};
    };
    
    ResultType isBalancedHelper(TreeNode * root) {
        if(!root) {
            return ResultType(true, 0);
        }
        ResultType left = isBalancedHelper(root->left);
        ResultType right = isBalancedHelper(root->right);
        int diff = abs(left.max_depth - right.max_depth);
        if(left.is_balanced && right.is_balanced && diff <= 1) {
            return ResultType(true, 1 + max(left.max_depth,  right.max_depth));
        }
        return ResultType(false, -1);
    }
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        return isBalancedHelper(root).is_balanced;
    }
};
