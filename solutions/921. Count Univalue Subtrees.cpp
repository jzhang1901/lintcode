/* 921. Count Univalue Subtrees
Description

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.
Have you met this question in a real interview?  
Example

Given root = {5,1,5,5,5,#,5}, return 4.

              5
             / \
            1   5
           / \   \
          5   5   5
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
// 分治法

class Solution {
public:
    struct ResultType {
        int nTrees;
        bool isUnivalue;
        ResultType( int nTrees, bool isUnivalue) :
            nTrees(nTrees), isUnivalue(isUnivalue) {}
            
        ~ResultType() {};
    };

    ResultType countUnivalSubtreesHelper(TreeNode * root) {
        if(!root) return ResultType(0, true);
        if(!root->left && !root->right) ResultType(root->val, true);
    
        bool isUnivalue = true;
        int nTrees = 0;
        
        if(root->left) {
            ResultType left = countUnivalSubtreesHelper(root->left); 
            isUnivalue = left.isUnivalue && root->val == root->left->val;
            nTrees += left.nTrees;
        }
        
        if(root->right) {
            ResultType right = countUnivalSubtreesHelper(root->right); 
            isUnivalue = right.isUnivalue && root->val == root->right->val;
            nTrees += right.nTrees;
        }    
        
        if(isUnivalue) nTrees += 1;
        return ResultType(nTrees, isUnivalue);
    }
    
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int countUnivalSubtrees(TreeNode * root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return countUnivalSubtreesHelper(root).nTrees;
    }
};