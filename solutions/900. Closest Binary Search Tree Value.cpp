/*
Description

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.

Have you met this question in a real interview?  
Example

Given root = {1}, target = 4.428571, return 1.
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
// Traverse approach, the worse case complexity is O(n)
class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        if(!root) return INT_MIN;
        double cVal = root->val;
        double minDiff = abs(cVal - target);
        if(root->left) {
            double leftVal = closestValue(root->left, target);
            if(abs(leftVal - target) < minDiff) {
                minDiff = abs(leftVal - target);
                cVal = leftVal;
            }
        }
        if(root->right) {
            double rightVal = closestValue(root->right, target);
            if(abs(rightVal - target) < minDiff) {
                minDiff = abs(rightVal - target);
                cVal = rightVal;
            }
        }
        return (int)cVal;
    }
};

