/*595. Binary Tree Longest Consecutive Sequence

Description

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
Have you met this question in a real interview?  
Example

For example,

   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2
*/

// Traverse and will reset the counter if current node value is larger than prev


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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    void longestConsecutiveHelper(TreeNode *root, int curPathLen) {
        if(!root) return;
        
        // save current best
        longest_path = max(longest_path, curPathLen);
        int expectedNxt = root->val + 1;
        
        int valPath = 1;
        if(root->left) {
            //　若发现下个节点和当前值之差不是１，则重置 counter
            if(root->left->val == expectedNxt) {
                valPath = curPathLen + 1;
            }
            longestConsecutiveHelper(root->left, valPath);  
        }
        if(root->right) {
            if(root->right->val == expectedNxt) {
                valPath = curPathLen + 1;
            } else {
                valPath = 1;
            }
            longestConsecutiveHelper(root->right, valPath);  
        }
    }
    int longestConsecutive(TreeNode * root) {
        if(!root) return 0;
        longest_path = 1;
        longestConsecutiveHelper(root, 1);　//开始的时候为１
        return longest_path;
    }
private:
    int  longest_path = 0;
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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    
    int longestConsecutiveHelper(TreeNode * root) {
        if(!root) return 0;
        int left = longestConsecutiveHelper(root->left);
        int right = longestConsecutiveHelper(root->right);
        
        int maxPath = 1; //至少还有个根节点
        
        if(root->left && root->val + 1 == root->left->val) {
            maxPath = max(1 + left, maxPath);
        }
        
        if(root->right && root->val + 1 == root->right->val) {
            maxPath = max(1 + right, maxPath);
        }
        
        result = max(result, maxPath);
        return maxPath;
    }
    
    int longestConsecutive(TreeNode * root){
        longestConsecutiveHelper(root);
        return result;
    }
private:
    int result = 0;
};