/*
Description

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
Have you met this question in a real interview?  
Example

Given a binary search Tree `{5,2,13}｀:

              5
            /   \
           2     13

Return the root of new tree

             18
            /   \
          20     13
*/
// 分析：　通常的in-order BST会给我们返回从小到大递增数组
//　如果我们以从大到小的方式遍历就其可

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
     * @return: the new root
     */
    void convertBSTHelper(TreeNode * root, int& sum) {
        if(!root) return;
        convertBSTHelper(root->right, sum);
        sum += root->val;
        root->val = sum;
        convertBSTHelper(root->left, sum);
    }
    
    TreeNode * convertBST(TreeNode * root) {
        int sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
};