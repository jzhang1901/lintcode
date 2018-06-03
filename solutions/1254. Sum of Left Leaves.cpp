/*
Description

Find the sum of all left leaves in a given binary tree.
Have you met this question in a real interview?  
Example

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
// 解题思路
// 这一题比较有意思, 再处理叶子节点的时候需要知道当前叶子节点是左边还是右边
// 这里的方法是用一个helper函数,再跌点的过程中把左右节点的信息传递进去

class Solution {
public:
    /**
     * @param root: t
     * @return: the sum of all left leaves
     */
    void sumOfLeftLeavesHelper(TreeNode * root, bool isLeft) {
        if(!root) return;
        if(isLeft && !root->left && !root->right) {
            leftLeavesSum += root->val;
            return;
        }
        sumOfLeftLeavesHelper(root->left, true);
        sumOfLeftLeavesHelper(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode * root) {
        if(!root) return 0;
        sumOfLeftLeavesHelper(root, false);
        return leftLeavesSum;
    }
int leftLeavesSum = 0;
};

//下面这个解法也很有意思,没有利用其他辅助函数
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// 非迭代的解法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t->left && !t->left->left && !t->left->right) res += t->left->val;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return res;
    }
};