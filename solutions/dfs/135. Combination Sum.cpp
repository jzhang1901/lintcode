/* 
135. Combination Sum
Description 
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Have you met this question in a real interview?  Yes
Example
Given candidate set [2,3,6,7] and target 7, a solution set is:

[7]
[2, 2, 3]

*/
/*
解题思路:
直觉上这道题有点类似于二叉树的的path sum 问题, 只是输入数据不是显式的树
https://www.lintcode.com/problem/binary-tree-path-sum/description

*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, 
                                       int target) {
       vector<vector<int>> results;
       vector<int> path;
       
       if(candidates.empty()) {
           results.push_back(path);
           return results;
       }
       
       //1. sort the candidates
       sort(candidates.begin(), candidates.end());
       dfs(candidates, 0, target, path, results);
       
       return results;
    }
    
private:
    void  dfs( vector<int> &candidates, 
               int start,
               int remainTarget, 
               vector<int> path, 
               vector<vector<int>> &results) {
                   
        if(remainTarget == 0) {
            results.push_back(path);
            return;
        }               
        
        for(int i = start; i < candidates.size(); i++) {
            
            if(remainTarget < 0) continue;
            
            path.push_back(candidates[i]);
            
            dfs(candidates, 
                i, //对比与subset 的问题, 这里是i不要递增,以达到重复取的目的
                remainTarget - candidates[i], 
                path, 
                results);
                
            path.pop_back();
            
        }           
                   
    }
};