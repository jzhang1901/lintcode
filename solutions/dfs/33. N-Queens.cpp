/* 33. N-Queens
Description
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Have you met this question in a real interview?  
Example
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]
Challenge
Can you do it without recursion?
*/

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > results;
        if( n <= 0 )
            return results;
        
        vector<int> cols;
        vector<bool> visited (n, false);
         
        dfs(cols, results, visited, n);

        return results;
    }
    
private:
    void dfs(vector<int> cols,
             vector<vector<string>> &results, 
             vector<bool> &visited,
             int n) {
        
        // recusion exit
        if(cols.size() == n) {
            results.push_back(drawResult(cols, n));
            return;
        }
        
        for(int col = 0; col < n; col++) {
            
            if(visited[col]) continue;
            
            if(!isValid(cols, col)) continue;
            
            visited[col] = true;
            
            cols.push_back(col);
            
            dfs(cols, results, visited, n);
            
            cols.pop_back();
            
            visited[col] = false;
        }
    }
    
    bool isValid(vector<int> &cols, int col)
    {
        int row = cols.size();
        
        for(int i = 0; i < row; ++i) {
            
            // if(cols[i] == col) {
            //     return false;
            // }
            
            if(i - cols[i] == row - col) {
                return false;
            }
            
            if(i + cols[i] == row + col) {
                return false;
            }
        }
        return true;
    }
    
    vector<string> drawResult(vector<int> &cols, int n) {
        
        vector<string> result;
        for(int i = 0; i < cols.size(); ++i) {
            string temp(n, '.');
            temp[cols[i]] = 'Q';
            result.push_back(temp);
        }
        
        return result;
    }
};