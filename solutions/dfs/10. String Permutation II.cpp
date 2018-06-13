/* 10. String Permutation II

Description
Given a string, find all permutations of it without duplicates.

Have you met this question in a real interview?  
Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].

*/

class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        
        vector<string> rets;
        
        string permutation;
        if(str.length() == 0) {
            rets.push_back(permutation);
            return rets;
        }
        
        vector<bool> visited(str.length(), false);
        sort(str.begin(), str.end());
        dfs(str, permutation, visited, rets);
        
        return rets;
    }
    
    void dfs(string &str, string p, vector<bool> &v, vector<string> &rets) {
        if(p.length() == str.length()) {
            rets.push_back(p);
        }
        for(int i = 0; i < str.length(); i++) {
            if(v[i]) continue;
            // 这里的操作是为了去重复
            if(i > 0 && str[i-1] == str[i] && !v[i-1]) continue;
            
            p.push_back(str[i]);
            v[i] = true;
            dfs(str, p, v, rets);
            v[i] = false;
            p.pop_back();
        }
        
    }
    
};