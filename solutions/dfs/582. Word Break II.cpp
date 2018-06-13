/* 582. Word Break II

Description
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Have you met this question in a real interview?  
Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].
*/

解题思路：

一定要记住的是，如果想要用记忆化搜索的方式，那么DFS一定要有返回值
