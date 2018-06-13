/*
Description

Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum average.
Have you met this question in a real interview?  
Example

Given a binary tree:

     1
   /   \
 -5     11
 / \   /  \
1   2 4    -2 

return the node 11.


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
    struct ResultType {
        double max_average;
        int sum;
        int size;
        TreeNode * node;
        ResultType(TreeNode * node, double max_average, int sum, int size) : 
            node(node),
            max_average(max_average),
            sum(sum),
            size(size) {};
        ~ResultType() {};
    };
    
    ResultType findSubtree2Helper(TreeNode * root) {
        if(!root) {
            return ResultType(nullptr, 0.0, 0, 0);
        }
        ResultType left = findSubtree2Helper(root->left);
        ResultType right = findSubtree2Helper(root->right);
    
        int sum = left.sum + right.sum + root->val;
        int size = left.size + right.size + 1;
        ResultType cur {root, (double)sum / (double)size, sum, size};
        
        
        if(right.node && right.max_average > cur.max_average) {
            cur.max_average = right.max_average;
            cur.node = right.node;
        } 
        
        if(left.node && left.max_average > cur.max_average) {
            cur.max_average = left.max_average;
            cur.node = left.node;
        }  

        return cur;
    }
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        ResultType ret = findSubtree2Helper(root);
        return ret.node;
    }
};