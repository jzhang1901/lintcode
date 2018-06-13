/* 427. Generate Parentheses
Description

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Have you met this question in a real interview?  
Example

Given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/
/*
解题思路：
每次递归的时候，如果左括号没有达到最大值，那么试试左边加一个
如果右括号的数量小于坐括号的数量，那么试试右括号加一个，　这个地方容易弄错
*/

class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string path;
        
        dfs(0, 0, n, path, results);    
        
        return results;
    }
    
    void dfs(int nLeft, 
             int nRight, 
             int n, 
             string path, 
             vector<string> &results) {
        
        if(nLeft == n && nRight == n) {
            results.push_back(path);
            return;
        } 
        
        if(nLeft < n)
            dfs(nLeft + 1, nRight, n, path + "(", results);
        
        
        if(nRight < nLeft)
            dfs(nLeft, nRight + 1, n, path + ")", results);
        
    }
    
};