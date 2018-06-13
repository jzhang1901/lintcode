/*
7. Binary Tree Inorder Traversal
Description

Given a binary tree, return the inorder traversal of its nodes' values.
Have you met this question in a real interview?  
Example

Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

 

return [1,3,2].
*/

// Note: this is a approach without recusion

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
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        std::stack<TreeNode*> s;
        vector<int> results;
        if(!root) return results;
        TreeNode *node;
        
        while(root) {
            s.push(root);
            root = root->left; //把所有左边子节点进栈
        }
        
        while(!s.empty()) {
            TreeNode *node = s.top(); //
            // do not pop the stack yet
            // Add the value to the results
            results.push_back(node->val);
            
            if(!node->right) {
                node = s.top(); s.pop();
                while(!s.empty() && s.top()->right == node) {
                    node = s.top();
                    s.pop();
                }
            } else {
                node = node->right;
                while(node) {
                    s.push(node);
                    node = node->left;
                }
            }
            
        }
        return results;
    }
};






