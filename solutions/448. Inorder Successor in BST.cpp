/*Description

Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)
Have you met this question in a real interview?  
Example

Given tree = [2,1] and node = 1:

  2
 /
1

return node 2.

Given tree = [2,1,3] and node = 2:

  2
 / \
1   3

return node 3.
Challenge

O(h), where h is the height of the BST.
*/