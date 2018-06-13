/* 829. Word Pattern II
Description
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

You may assume both pattern and str contains only lowercase letters.

Have you met this question in a real interview?  
Example
Given pattern = "abab", str = "redblueredblue", return true.
Given pattern = "aaaa", str = "asdasdasdasd", return true.
Given pattern = "aabb", str = "xyzabcxzyabc", return false.

*/
/*
这个地方放了很多次错误
sIdx + len <= s.length()　不是　sIdx + len < s.length()
for(int len = 1; sIdx + len <= s.length(); len++)
*/

class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        
        unordered_map<char, string> dict;
        
        unordered_set<string> used;

        return dfs(pattern, 0, str, 0, dict, used);
    }
    
private:
    bool dfs(const string &p, 
             int pIdx, 
             const string &s, 
             int sIdx, 
             unordered_map<char, string> &dict,
             unordered_set<string> &used) {
        
        if(pIdx >= p.length() && sIdx >= s.length()) return true;
        
        if(pIdx == p.length() || sIdx == s.length()) return false;
        
        char pChar = p[pIdx];

        if(dict.count(pChar)) {
            
            string s0 = dict[pChar];
            string s1 = s.substr(sIdx, s0.length());
            
            if(s0 != s1) return false;
            
            return dfs(p, pIdx + 1, s, sIdx + s0.length(), dict, used);
        } 
        
        for(int len = 1; sIdx + len <= s.length(); len++) {
            
            string s0 = s.substr(sIdx, len);
            
            if(used.count(s0)) continue;
            
            dict[pChar] = s0;
            used.insert(s0);
            
            if(dfs(p, pIdx + 1, s, sIdx + len, dict, used)) return true;
            
            
            used.erase(s0);
            dict.erase(pChar);
        }
        
        return false;
    }
private:
    bool isMatched = false;
};