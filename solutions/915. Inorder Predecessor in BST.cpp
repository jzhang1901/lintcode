/*
915. Inorder Predecessor in BST
Description

Given a binary search tree and a node in it, find the in-order predecessor of that node in the BST.

If the given node has no in-order predecessor in the tree, return null
Have you met this question in a real interview?  
Example

Given root = {2,1,3}, p = 1, return null.
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
// No recursion method 
class Solution {
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        if(!root || !p) return root;
        std::stack<TreeNode*> s;;
        TreeNode *predecessor = NULL;
        while(root) {
            s.push(root);
            root = root->left;
        }    
    
        while(!s.empty()) {
            TreeNode *node = s.top();
            if(node == p) return predecessor;
            predecessor = node;
            if(node->right == NULL) {
                node = s.top(); s.pop();
                while(!s.empty() && s.top()->right == node) {
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
        return NULL;
    }
};

// Now let's do some recursion 

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
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode *mostRight(TreeNode *root) {
        while(root->right) root = root->right;
        return root;
    };
    // 利用BST的性质帮助我们加速查找
    // 
    TreeNode * inorderPredecessor(TreeNode * root, 
                                  TreeNode * p) {
        if(!root || !p) return NULL; 

        if(root->val < p->val) {
            predecessor = root;
            return inorderPredecessor(root->right, p);
        } else if(root->val > p->val) {
            return inorderPredecessor(root->left, p);
        } else {
            if(root->left) {
               return mostRight(root->left);
            }
            return predecessor;
        }
    }
private:
    TreeNode *predecessor;

};

public class Solution {
    
    TreeNode predecessor = null;
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        helper(root, p);
        return predecessor;
    }
    
    private void helper(TreeNode root, TreeNode p){
        if (root == null){
            return;
        }
        
        helper(root.left, p);
        if (root == p){
            if (root.left != null){
                predecessor = root.left;
            } 
            return;
        }
        
        if (root.val < p.val){
            predecessor = root;
            helper(root.right, p);
        }
    }
}