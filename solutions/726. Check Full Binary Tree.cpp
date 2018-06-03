/* 726. Check Full Binary Tree
Description

A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. Conversely, there is no node in a full binary tree, which has one child node. More information about full binary trees can be found here.

Full Binary Tree
      1
     / \
    2   3
   / \
  4   5

Not a Full Binary Tree
      1
     / \
    2   3
   / 
  4   

Have you met this question in a real interview?  
Example

Given tree {1,2,3}, return true
Given tree {1,2,3,4}, return false
Given tree {1,2,3,4,5} return true


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
     * @param root: the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        if(!root) return true;
        bool left = isFullTree(root->left);
        bool right = isFullTree(root->right);
        if(!left || !right) return false;
        if(root->left && !root->right) return false;
        if(!root->left && root->right) return false;
        return true;
    }
};