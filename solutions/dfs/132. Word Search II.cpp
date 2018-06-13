/*  132. Word Search II
Description
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. One character only be used once in one word.

Have you met this question in a real interview?  
Example
Given matrix:

doaf
agai
dcan
and dictionary:

{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}


dog:
doaf
agai
dcan
dad:

doaf
agai
dcan
can:

doaf
agai
dcan
again:

doaf
agai
dcan
Challenge
Using trie to implement your algorithm.
*/

// 类似与Java的解法，纯DFS搜索，没有Trie 优化版本

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, 
                                vector<string> &words) {
                                    
        unordered_set<string> prefixDict; 

        unordered_set<string> wordsDict;
        
        buildPrefixDict(words, prefixDict);

        for(const auto & word : words) {
            wordsDict.insert(word);
        }
        
        unordered_set<string> results;
        

        const int nRows = board.size();
        const int nCols = board[0].size();
        
        vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
                
        for(int i = 0; i < nRows; i++) {
            
            for(int j = 0; j < nCols; j++) {
                
                string word;
                word.push_back(board[i][j]);
                
                visited[i][j] = true;              
                if(prefixDict.count(word)) {
                    dfs(board, wordsDict, prefixDict, visited, word, i, j, results);
                }
                visited[i][j] = false;
            }
        }
        
        vector<string> tmp;
        
        for(const auto & it : results)
            tmp.push_back(it);
        
        return tmp;
    }

private:

    const vector<int> dx = {0, 1, -1, 0};
    const vector<int> dy = {1, 0, 0, -1};
        
    void dfs(vector<vector<char>> &board, 
             unordered_set<string> &wordsDict, 
             unordered_set<string> &prefixDict,
             vector<vector<bool>> &visited,
             string word,
             int row, 
             int col, 
             unordered_set<string> &results) {
        
        if(!isValidPosition(board, row, col)) return;
        
        if(wordsDict.count(word) && !results.count(word)) {
            results.insert(word);
        }
            
        for(int i = 0; i < 4; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];
            
            if(!isValidPosition(board, nx, ny) || visited[nx][ny]) continue;
            
            word.push_back(board[nx][ny]);
              
            if(!prefixDict.count(word)) {
                word.pop_back();
                continue;
            }
            
            visited[nx][ny] = true;
            dfs(board, wordsDict, prefixDict, visited, word, nx, ny, results);
            word.pop_back();
            visited[nx][ny] = false;  
        }
        
    }

    bool isValidPosition(vector<vector<char>> &board, int row, int col) {
        const int nRows = board.size();
        const int nCols = board[0].size();
        if(row < 0 || col < 0 || row >= nRows || col >= nCols) return false;
        return true;
    }

    void buildPrefixDict(vector<string> &words, 
         unordered_set<string> &dict) {
        
        for(const auto & word : words) {
            for(int len = 1; len < word.length(); len++) {
                
                string prefix = word.substr(0, len);
                
                if(dict.count(prefix) == 0) {
                    dict.insert(prefix);
                }
                
            }
            dict.insert(word);
        }    
    }
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, 
                                vector<string> &words) {
                                
        unordered_map<string, bool> prefixDict; 


        getPrefixSet(words, prefixDict);
    
    
        unordered_set<string> results;
        
        const int nRows = board.size();
        const int nCols = board[0].size();
        
        vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
        
        for(int i = 0; i < nRows; i++) {
            
            for(int j = 0; j < nCols; j++) {
    
                string word;
                word.push_back(board[i][j]);
                
                if(!prefixDict.count(word)) continue;
                
                visited[i][j] = true;
                
                dfs(board, 
                    prefixDict, 
                    visited, 
                    word, 
                    i, 
                    j, 
                    results);
    
                visited[i][j] = false;
            }
        }
        
        vector<string> tmp;
        
        for(const auto & it : results)
            tmp.push_back(it);
        
        return tmp;
    }

private:

        
    void dfs(vector<vector<char>> &board, 
             unordered_map<string, bool> &prefixDict,
             vector<vector<bool>> &visited,
             string word,
             int row, 
             int col, 
             unordered_set<string> &results) {

        if(!isValidPosition(board, row, col)) return;
        
        vector<int> dx = {0, 1, -1, 0};
        vector<int> dy = {1, 0, 0, -1};
    
    
        if(prefixDict[word] && !results.count(word)) {
            results.insert(word);
        }
    
        for(int i = 0; i < 4; i++) {
            
            int adjX = row + dx[i];
            int adjY = col + dy[i];
            
            
            if(!isValidPosition(board, adjX, adjY) || visited[adjX][adjY]) continue;
            
            word.push_back(board[adjX][adjY]);
            
            if(!prefixDict.count(word)) {
                word.pop_back();
                continue;
            }
            
            visited[adjX][adjY] = true;
            
            dfs(board, prefixDict, visited, word, adjX, adjY, results);
            
            word.pop_back();
            visited[adjX][adjY] = false;
        }
        
    }

    bool isValidPosition(vector<vector<char>> &board, int row, int col) {
        const int nRows = board.size();
        const int nCols = board[0].size();
        if(row < 0 || col < 0 || row >= nRows || col >= nCols) return false;
        return true;
    }

    void getPrefixSet(vector<string> &words, 
                         unordered_map<string, bool> &dict) {
        
        for(const auto & word : words) {
            for(int len = 1; len < word.length(); len++) {
                
                string prefix = word.substr(0, len);
                
                if(dict.count(prefix) == 0) {
                    dict[prefix] = false;
                }
                
            }
            
            dict[word] = true;
        }    
    }
};


