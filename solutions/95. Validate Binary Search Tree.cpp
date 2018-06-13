/*
Description

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    A single node tree is a BST

Have you met this question in a real interview?  
Example

An example:

  2
 / \
1   4
   / \
  3   5

The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    struct ResultType {
        long long min_val;
        long long max_val;
        bool is_bst;
        ResultType(long long min, long long max, bool is_bst) :
            min_val(min), max_val(max), is_bst(is_bst) {};
        ~ResultType() {};
    };
    
    ResultType isValidBSTHelper(TreeNode *root) {
        if(!root) {
            return ResultType(LONG_MAX, LONG_MIN, true);
        }
        if(!root->left && !root->right) {
            return ResultType(root->val, root->val, true);
        }
        ResultType ret(root->val, root->val, false);
        ResultType left = isValidBSTHelper(root->left);
        ResultType right = isValidBSTHelper(root->right);
        if(left.is_bst && right.is_bst) {
            ret.min_val = min(min(left.min_val, right.min_val), (long long)root->val);
            ret.max_val = max(max(left.max_val, right.max_val), (long long)root->val);
            ret.is_bst  = 
                left.max_val < root->val && 
                right.min_val > root->val;
            return ret;
        }
        
        return ResultType(INT_MAX, INT_MIN, false);
    }
    bool isValidBST(TreeNode * root) {
        return isValidBSTHelper(root).is_bst;
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if(!root) {
            return true;
        }
        if(isValidBST(root->left)) {
            if((long long)root->val > prev_val) {
                prev_val = root->val;
            } else {
                return false;
            }
        } else {
            return false;
        }
  
        return isValidBST(root->right);
    }
long long prev_val = LONG_MIN;
};



