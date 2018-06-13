/*480. Binary Tree Paths

Description

Given a binary tree, return all root-to-leaf paths.
Have you met this question in a real interview?  
Example

Given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
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
// Traverse 
class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    void binaryTreePathsHelper(TreeNode * root, 
                               string path, 
                               vector<string> &paths) {
        if(!root) return;
        // leaf node
        if(!root->left && !root->right) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }
        if(root->left) {
            binaryTreePathsHelper(root->left, 
                                  path + to_string(root->val) + "->",
                                  paths);
        }
        if(root->right) {
            binaryTreePathsHelper(root->right, 
                                  path + to_string(root->val) + "->",
                                  paths);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string>  paths;
        if(!root) return paths;
        binaryTreePathsHelper(root, "", paths);
        
        return paths;
    }
};

// Divide and Conquer 
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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> paths;
        if(!root) return paths;
        if(!root->left && !root->right) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);
        
        for(const auto & p : leftPaths) {
            paths.push_back(to_string(root->val) + "->" + p);
        }
        
        for(const auto & p : rightPaths) {
            paths.push_back(to_string(root->val) + "->" + p);
        }
        return paths;
    }
    
    
};