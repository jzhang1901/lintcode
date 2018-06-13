/* 34. N-Queens II
Description
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Have you met this question in a real interview?  
Example
For n=4, there are 2 distinct solutions.
*/


class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        vector<int> cols;
        
        dfs(cols, n);
        
        return nSolutions;
    }
    
private:
    
    int nSolutions = 0;
    
    int dfs(vector<int> cols, int n) {
        
        if(cols.size() == n) {
            nSolutions++;
        }
        
        for(int col = 0; col < n; col++) {

            if(!isValid(cols, col)) continue;
            
            cols.push_back(col);
            
            dfs(cols, n);
            
            cols.pop_back();
        }
    }

    bool isValid(std::vector<int> cols, int col) {
        
        int row = cols.size();
        
        for(int i = 0; i < row; i++) {
            
            // same row attack
            if(cols[i] == col) return false;
            
            // diagonal attack
            if(i + cols[i] == row + col) return false;
            
            // off diagonal attack
            if(i - cols[i] == row - col) return false;    
        }
        
        return true;
    }
};