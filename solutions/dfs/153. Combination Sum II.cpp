/*
153. Combination Sum II

Description
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Have you met this question in a real interview?  Yes
Example
Given candidate set [10,1,6,7,2,1,5] and target 8,

A solution set is:

[
  [1,7],
  [1,2,5],
  [2,6],
  [1,1,6]
]
*/

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        
       vector<vector<int>> results;
       
       vector<int> path;
       
       if(num.empty()) {           
           return results;
       }
       
       //1. sort the candidates
       sort(num.begin(), num.end());
       dfs(num, 0, target, path, results);
       
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
            
            // 去重复1, 这里的目的再与保证
            if(i > start && candidates[i-1] == candidates[i]) continue;
            
            path.push_back(candidates[i]);
            
            dfs(candidates, 
                i+1, //去重复 2
                remainTarget - candidates[i], 
                path, 
                results);
                
            path.pop_back();
            
        }           
                   
    }
};