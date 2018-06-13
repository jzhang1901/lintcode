/*
Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> ret;
        if(!root) return ret;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> curLevel;
            const size_t l = q.size();
            for(int i = 0; i < l; i++) {
                TreeNode *cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ret.push_back(curLevel);
        }
        
        
        return ret;
    }
};