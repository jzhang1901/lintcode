/* 652. Factorization
Description

A non-negative numbers can be regarded as product of its factors.
Write a function that takes an integer n and return all possible combinations of its factors.

    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combination.

Have you met this question in a real interview?  
Example

Given n = 8
return [[2,2,2],[2,4]]
// 8 = 2 x 2 x 2 = 2 x 4.

Given n = 1
return []

Given n = 12
return [[2,6],[2,2,3],[3,4]]
*/


// 尝试用记忆化搜索来优化
class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        
        vector<string> result;
        
        if(wordDict.empty() || s.empty()) return result;
        
        unordered_map<string, vector<string>> hash;
        
        return dfs(s, wordDict, hash);
    }

private:

    vector<string> dfs(const string &s, 
                       unordered_set<string> &wordDict,
                       unordered_map<string, vector<string>> &hash) {
                           
        vector<string> result;
        
        if(hash.count(s)) return hash[s];
        
        if(wordDict.count(s)) {
            result.push_back(s);
        }
        
        for(int len = 1; len < s.length(); len++) {
            
            string s0 = s.substr(0, len);
            if(wordDict.count(s0) == 0) continue;
            
            string s1 = s.substr(len, s.length() - len);
            
            vector<string> subResult = dfs(s1, wordDict, hash);
            
            for(const auto & it : subResult) {
                result.push_back(s0 + " " + it);
            }
        }
        
        hash[s] = result;
        return result;                       
    }

};


class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> results;
        
        if(n <= 1) {
            return results;    
        }
        vector<int> path; 
        
        dfs(n, n, path, results);
        
        return results;
    }
    
    void dfs(int n, 
             int remain, 
             vector<int> path, 
             vector<vector<int>> &results) {
                 
        // find a good set of factors, return          
        if(remain == 1) {
            if(path.size() > 1)
                results.push_back(path);　//错误１
            return;
        }
        
        for(int i = path.empty() ? 2 : path[path.size() - 1]; //错误2
            i <= remain; 
            i++) {
            
            if(remain % i) continue; // not a valid factor
            
            path.push_back(i);
            dfs(n, remain / i, path, results);
            path.pop_back();
        }
        
    }
};


