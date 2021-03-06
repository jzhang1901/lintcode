/* 1165. Subtree of Another Tree
Description

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
Have you met this question in a real interview?  
Example

Example 1:

Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:

Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool isSame(TreeNode * s, TreeNode * t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        
        return isSame(s->left, t->left) && 
            isSame(s->right, t->right);
    }
    /**
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values with a subtree of s
     */
    bool isSubtree(TreeNode * s, TreeNode * t) {
        if (!s) return false;
        if(isSame(s, t)) return true;
        
        return isSubtree(s->left, t) || isSubtree(s->right,t);
    }
};