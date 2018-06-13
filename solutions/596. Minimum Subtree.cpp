/*
Description

Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.
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

class TreeNode {
public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
          this->left = this->right = NULL;
      }
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    int findSubtreeSum(TreeNode * root, 
                    unordered_map<TreeNode*, int> &hash, 
                    int &curMin, 
                    TreeNode* &result) {
        if(!root) return 0;
        if(hash.count(root) != 0) {
            if(hash[root] < curMin) {
                curMin = hash[root];
                result = root;
            }
            return hash[root];
        }
        hash[root] = root->val;
        
        if(root->left) {
            hash[root] += findSubtreeSum(root->left, hash, curMin, result);
        }
        if(root->right) {
            hash[root] += findSubtreeSum(root->right, hash, curMin, result);
        }
        if(hash[root] < curMin) {
            curMin = hash[root];
            result = root;
        }
        return hash[root];
    }
    
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        if(!root) return root;
        unordered_map<TreeNode*, int> hash;
        int curMin = INT_MAX;
        TreeNode *ret = nullptr;
        findSubtreeSum(root, hash, curMin, ret); 
           
        return ret;
    }
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
     * @return: the root of the minimum subtree
     */
    int subTreeSum(TreeNode *root) {
        if(!root) return 0;
        int sum = root->val + subTreeSum(root->left) + subTreeSum(root->right);
        if(sum < minSub) {
            minSub = sum;
            node = root;
        }
        return sum;
    }
    TreeNode * findSubtree(TreeNode * root) {
        if(!root) return root;
        subTreeSum(root);
        return node;
    }
private:
    TreeNode * node = NULL;
    int minSub = INT_MAX;
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
 
// Use divide and conquer method
class Solution {
public:
    class ResultType {
    public:
        ResultType(TreeNode *node, int sum, int minSum) : 
            minNode(node), sum(sum), minSum (minSum) {
        }
        ~ResultType() {};
        TreeNode *minNode;
        int sum;
        int minSum;
    };
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    int subTreeSum(TreeNode *root) {
        if(!root) return 0;
        int sum = root->val + subTreeSum(root->left) + subTreeSum(root->right);
        if(sum < minSub) {
            minSub = sum;
            node = root;
        }
        return sum;
    }
    
    ResultType findSubtreeHelper(TreeNode * root) {
        if(!root) {
            return ResultType(NULL, 0, INT_MAX);
        }
        
        ResultType left = findSubtreeHelper(root->left);
        ResultType right = findSubtreeHelper(root->right);
        ResultType ret = 
            ResultType(root, 
            root->val + left.sum + right.sum, 
            root->val + left.sum + right.sum);
            
        if(left.minSum < ret.minSum) {
            ret.minNode = left.minNode;
            ret.minSum = left.minSum;
        }
        if(right.minSum < ret.minSum) {
            ret.minNode = right.minNode;
            ret.minSum = right.minSum;
        }
        return ret;
    }
    
    TreeNode * findSubtree(TreeNode * root) {
        if(!root) return root;
        ResultType ret = findSubtreeHelper(root);
        return ret.minNode;
    }
private:
    TreeNode * node = NULL;
    int minSub = INT_MAX;
};