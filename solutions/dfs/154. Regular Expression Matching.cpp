/* 154. Regular Expression Matching
Description
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


The function prototype should be:

bool isMatch(string s, string p)

Have you met this question in a real interview?  
Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/
/*
解题思路分析：
不同与　192. Wildcard Matching，　在这里 *和它之前的字符需要一起看

如果 p[j+1] == '*', 
  case 1: p[j], p[j+1]可以完全不算，那么我们只要继续 match s[i] 和 p[j+2]
  case 2: aaaab, a*b, s[i] == p[j],那么这里advance s[i],　继续match s[i+1], p[j]
如果 p[j+1] != '*'
    那么我们要求 s[i] == p[j],　然后继续匹配 s[i+1],p[j+1]
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        
        vector<vector<bool>> visited (s.length(), 
                                      vector<bool>(p.length(), false));

        vector<vector<bool>> memo    (s.length(), 
                                      vector<bool>(p.length(), false));
                                      
                                      
        return dfs(s, 0, p, 0, visited, memo);

    }
    
private:
    bool dfs(const string &s, 
             int sindex, 
             const string &p, 
             int pindex, 
             vector<vector<bool>> &visited,
             vector<vector<bool>> &memo) {
        
        
        if(pindex == p.length()) return (sindex == s.length());             
        if(sindex == s.length()) return isRegexEmpty(p, pindex);
        
        if(visited[sindex][pindex]) return memo[sindex][pindex];
        
        bool matched = false;
        
        if(pindex + 1 < p.length() && p[pindex + 1] == '*') {
            
            matched = dfs(s, sindex, p, pindex + 2, visited, memo) ||
                      (charMatched(s[sindex], p[pindex]) && 
                      dfs(s, sindex + 1, p, pindex, visited, memo));
                      
            
        } else {
            
            matched = charMatched(s[sindex], p[pindex]) && 
                      dfs(s, sindex + 1, p, pindex + 1, visited, memo);
            
        }
        
        visited[sindex][pindex] = true;
        memo[sindex][pindex] = matched;
        
        return matched;
    }
    
    bool charMatched(char a, char b) {
        if(a == b) return true;
        if(a == '.' || b == '.') return true;
        return false;
    }
    
    bool isRegexEmpty(const string & s, int start) {

        if(start >= s.length()) return true;
        if(start + 1 >= s.length()) return false;
        
        int i;
        for(i = start; i < s.length(); i += 2) {
            if(s[i+1] != '*') return false;
        }
        
        for(int j = i; j < s.length(); j++) {
            if(s[j] != '*') return false;
        }
        return true;
    }
};
