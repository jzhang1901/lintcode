/* 192. Wildcard Matching

Description
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(const string &s, const string &p) {
        
        vector<vector<bool>> visited(s.length(), 
                                     vector<bool>(p.length(), false));
                                     
        vector<vector<bool>> memo(s.length(), 
                                  vector<bool>(p.length(), false));     
        
        return dfs(s, 0, p, 0, visited, memo);
    }
    
private:
    bool dfs(const string &s, 
            int sindex, 
            const string &p, 
            int pindex, 
            vector<vector<bool>> &visited, 
            vector<vector<bool>> &memo
            ) {
                
        // Recursion exit
        if(sindex == s.length()) 
            return isAllStart(p, pindex);
        
        if(pindex == p.length())
            return sindex == s.length();
        
        if(visited[sindex][pindex])
            return memo[sindex][pindex];
        
        // Recursion body
        bool matched = false;
        
        if(p[pindex] == '*') {
            matched = dfs(s, sindex + 1, p, pindex, visited, memo) || // d document vs doc* case
                      dfs(s, sindex, p, pindex + 1, visited, memo); // ab vs *ab case
        } else {
            matched = charMatch(s[sindex], p[pindex]) && dfs(s, sindex + 1, p, pindex + 1, visited, memo);
        }
        
        visited[sindex][pindex] = true;
        
        memo[sindex][pindex] = matched;
        
        return matched;
    }
    
    
    bool isAllStart(const string & s, int start) {
        for(int i = start; i < s.length(); i++) {
            if(s[i] != '*') return false;
        }
        return true;
    }
    
    
    bool charMatch(char a, char b) {
        if(a == b) return true;
        if(a == '?' || b == '?') return true;
        return false;
    }
};