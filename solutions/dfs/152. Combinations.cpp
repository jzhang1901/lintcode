/* 152. Combinations
Description
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You don't need to care the order of combinations, but you should make sure the numbers in a combination are sorted.

Have you met this question in a real interview?  Yes
Example
Given n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4]
]
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> results;
        
        if(n == 0 || k == 0) return results;
        
        vector<int> current;
        
        dfs(1, n, k, current, results);
        
        return results;
    }
    
    
private:
    void dfs(int s, 
             int n, 
             int k, 
             vector<int> current, 
             vector<vector<int>> &results) {
        
        if( k == 0) {
            results.push_back(current);
            return;
        }
        
        for(int i = s; i <= n; i++) {
            
            current.push_back(i);
            
            dfs(i+1, n, k-1, current, results);
            
            current.pop_back();
        }
    }
};