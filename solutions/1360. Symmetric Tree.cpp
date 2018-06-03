/*Description

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Bonus points if you could solve it both recursively and iteratively.
Have you met this question in a real interview?  
Example

For example, this binary tree {1,2,2,3,4,4,3} is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following {1,2,2,#,3,#,3} is not:

    1
   / \
  2   2
   \   \
   3    3
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
     * @param root: root of the given tree
     * @return: whether it is a mirror of itself 
     */
    bool isMirror(TreeNode * left, TreeNode * right) {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val == right->val) {
            return isMirror(left->left, right->right) &&
                   isMirror(left->right, right->left);
        } else 
            return false;
    }
    
    bool isSymmetric(TreeNode * root) {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }
};
