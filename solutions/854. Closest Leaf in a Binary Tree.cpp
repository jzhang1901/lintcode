/*
854. Closest Leaf in a Binary Tree
Description

Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.If there is more than one answer, return to the leftmost.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

1.root represents a binary tree with at least 1 node and at most 1000 nodes.
2.Every node has a unique node.val in range [1, 1000].
3.There exists some node in the given binary tree for which node.val == k.
Have you met this question in a real interview?  
Example

Example 1:

Given:
root = {1, 3, 2}, k = 1
Diagram of binary tree:
          1
         / \
        3   2

Return: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.

Example 2:

Given:
root = {1}, k = 1
Return: 1

Explanation: The nearest leaf node is the root node itself.

Example 3:

Given:
root = {1,2,3,4,#,#,#,5,#,6}, k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Return: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.

*/
/*==========================================================================================================

解题思路：
1. 这个问题类似于图问题里面的最短路径，需要想办法把树结构转换为图结构
2. 在树结构有点类似与有向图，需要建立从根节点到目标节点的反向连接，然后从目标节点出发，用BFS的方式去找到所以的叶子节点
3. 用unordered_map去建立反向连接，但是对于目标节点那个分支不需要反向连接，因为目标节点可以直接访问它的叶子节点
4. 建立好的新的图中　每一个节点会有三个out degree (L,R, P)，　需要用另外一个hash 表保证不会有重复
参考链接：
http://www.cnblogs.com/grandyang/p/8245586.html

该链接下面还有个很巧妙的解法　暂时还没有研究
==========================================================================================================*/

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

class Solution {
public:
    void buildTreeGraph(TreeNode *root, int k) {
        if(!root) return;
        // no need to build graph for target branch
        if(root->val == k) {
            target = root; // log the target as our graph start
            return; 
        }
        if(root->left) {
            hash[root->left] = root;
            buildTreeGraph(root->left, k);
        }
        if(root->right) {
            hash[root->right] = root;
            buildTreeGraph(root->right, k);
        }
    }

    int findClosestLeafBFS(TreeNode * start, int k) {
        if(!start) return -1;
        unordered_set<TreeNode*> visited;
        std::queue<TreeNode*> q;
        q.push(start);
        visited.insert(start);
        
        while(!q.empty()) {
            TreeNode *head = q.front(); q.pop();
            if(!head->left && !head->right) return head->val;
            
            if(head->left && !visited.count(head->left)) {
                q.push(head->left);
                visited.insert(head->left);
            }
            if(head->right && !visited.count(head->right)) {
                q.push(head->right);
                visited.insert(head->right);
            }
            if(hash.count(head) && !visited.count(hash[head])) {
                q.push(hash[head]);
                visited.insert(hash[head]);
            }
        }
        return -1;
    }
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
    int findClosestLeaf(TreeNode * root, int k) {
        if(!root) return -1;
        if(!root->left && !root->right && root->val == k) return root->val;
        buildTreeGraph(root, k);
        return findClosestLeafBFS(target, k);
    }
private:
    unordered_map<TreeNode*, TreeNode *> hash;
    TreeNode *target = NULL;
};
