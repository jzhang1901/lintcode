/*
Description

Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.
Have you met this question in a real interview?  
Example

Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3

return

[
  [1, 2, 2],
  [1, 4]
]
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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    void binaryTreePathSumHelper(TreeNode * root, 
                                int target, 
                                vector<int> path, 
                                vector<vector<int>> &paths) {
        if(!root) return;
        if(target == 0 && !root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        
        if(root->left) {
            path.push_back(root->left->val);
            binaryTreePathSumHelper(root->left, 
                                    target - root->left->val, 
                                    path, 
                                    paths);
            path.pop_back();
        }
        if(root->right) {
            path.push_back(root->right->val);
            binaryTreePathSumHelper(root->right, 
                                    target - root->right->val, 
                                    path, 
                                    paths);
            path.pop_back();
        }                           
    }


    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<int> path; 
        path.push_back(root->val);
        binaryTreePathSumHelper(root, target - root->val, path, ret);
        return ret;
    }
};