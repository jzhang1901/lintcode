/*
Description

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:

Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".


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
     * @param t: the root of tree
     * @return: return a string
     */
    void tree2strHelper(TreeNode *root, string& path) {
        if(!root) {
            return;
        }
        path += to_string(root->val);
        
        if(root->left) {
            path += "(";
            tree2strHelper(root->left, path); 
            path += ")";
        }
        if(root->right) {
            if(!root->left) {
               path += "()"; 
            }
            path += "(";
            tree2strHelper(root->right, path); 
            path += ")";   
        }
    }
    string tree2str(TreeNode * t) {
        string ret;
        tree2strHelper(t, ret);
        return ret;
    }
};