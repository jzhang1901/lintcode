/*
1094. Second Minimum Node In a Binary Tree

Description

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.
Have you met this question in a real interview?  
Example

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

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

//
// 解题思路,这里用tranverse的方法去接,注意重复的情况
// 1. 如果当前值比最近值小,那么更新最小值
// 2. 如果当前值不比最小值小,而且不等于最小值,那么再去和第二小的值比较
// 很重要的一点是要保证当前值不等于最小值,不然会有错误的结果
// 注意: 这里犯错了, 根据题目条件根节点一定是最小的,所以只要找到次小的即可
//

class Solution {
public:
    /**
     * @param root: the root
     * @return: the second minimum value in the set made of all the nodes' value in the whole tree
     */
    void findSecondMinimumValueHelper(TreeNode * root) {
        if(!root) return;
        
        if(root->val < secondMin && root->val != firstMin) {
            secondMin = root->val;
        }
        
        findSecondMinimumValueHelper(root->left);
        findSecondMinimumValueHelper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode * root) {
        if(!root) return -1;
        firstMin = root->val;
        findSecondMinimumValueHelper(root);
        if(firstMin == secondMin) return -1;
        if(secondMin == INT_MAX) return -1;
        return secondMin;
    }
private:
    int firstMin  = INT_MAX;
    int secondMin = INT_MAX;
};

// Divide & Conquer 的解法
// 解题思路
// 因为根节点一定是最小的,那么左边的次小值要么就是左节点的值 (不相等), 要么再迭代一层
// 同理,那么右边的次小值要么就是右节点的值 (不相等), 要么再迭代一层

class Solution {
public:
    /**
     * @param root: the root
     * @return: the second minimum value in the set made of all the nodes' value in the whole tree
     */
    int findSecondMinimumValue(TreeNode * root) {
        if(!root->left) return -1;
        
        int left = 
            root->left->val == root->val ?
            findSecondMinimumValue(root->left) :
            root->left->val;
            
        int right = 
            root->right->val == root->val ?
            findSecondMinimumValue(root->right) :
            root->right->val;

        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};