/* 780. Remove Invalid Parentheses

Description

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

The input string may contain letters other than the parentheses ( and ).
Have you met this question in a real interview?  
Example

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


*/

#include <vector>
#include <string>
#include <stack>
using namespace std;

/* 780. Remove Invalid Parentheses

Description

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

The input string may contain letters other than the parentheses ( and ).
Have you met this question in a real interview?  
Example

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


*/

/* 780. Remove Invalid Parentheses

Description

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

The input string may contain letters other than the parentheses ( and ).
Have you met this question in a real interview?  
Example

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


*/


class Solution {
public:

   bool isValidParentheses(const string& s){
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') cnt++;
            if (c == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return (cnt == 0);
    }
    
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(const string &s) {
        
        unordered_set<string> results;
        vector<string> results2;
        
        if(s.empty()) {
            results2.push_back("");
            return results2;
        }
        
        if(isValidParentheses(s)) {
            results2.push_back(s);
            return results2;
        }
        
        for(int nRemoves = 1; nRemoves < s.length(); nRemoves++) {

            dfs(s, nRemoves, 0, "", results);

            if(!results.empty()) break;
        }
        
        if(results.empty()) results.insert("");   
        

        for(const auto it : results) 
            results2.push_back(it);
        
        return results2;
    }
    
    void dfs(const string &s, 
             int nRemoves, 
             int start,
             string cur, 
             unordered_set<string> &results) {
                 
        if(nRemoves == 0) {
            if(start < s.length()) 
               cur += s.substr(start, s.length() - start); 
            
            if(isValidParentheses(cur)) results.insert(cur);
            return;
        }
        
        while(start < s.length() && 
             s[start] != '(' && s[start] != ')')  {
            cur.push_back(s[start++]);
        }
        
        if(start == s.length()) {
            if(isValidParentheses(cur)) results.insert(cur);
            return;
        }
        
        // remove current 
        dfs(s, nRemoves - 1, start + 1, cur, results);
        
        // do not remove current
        cur.push_back(s[start]);
        dfs(s, nRemoves, start + 1, cur, results);
        cur.pop_back();
    }
};
    