/* 1353. Sum Root to Leaf Numbers
Description

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

A leaf is a node with no children.
Have you met this question in a real interview?  
Example

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
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
     * @param root: the root of the tree
     * @return: the total sum of all root-to-leaf numbers
     */
    void sumNumbersHelper(TreeNode *root, int accumulate) {
        if(!root) return;
        
        int accumulate2 = accumulate * 10 + root->val;
        
        if(!root->left && !root->right) {
            sum += accumulate2;
            return;
        }

        sumNumbersHelper(root->left, accumulate2);
        sumNumbersHelper(root->right, accumulate2);
    }
    
    int sumNumbers(TreeNode * root) {
        if(!root) return 0;
        sumNumbersHelper(root, 0);
        return sum;
    }
private:
int sum = 0;    
    
};