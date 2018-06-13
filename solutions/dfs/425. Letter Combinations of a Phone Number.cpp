/* 425. Letter Combinations of a Phone Number
Description
Given a digit string excluded 01, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Cellphone

Although the above answer is in lexicographical order, your answer could be in any order you want.

Have you met this question in a real interview?  
Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
*/
/*
解题思路分析：
这里非常类似于permutation，要找到所有N数字所代表的字母的组合

注意这里有个雷点，应该只保留长度正确的结果，而不是检查start index
否则会出现如下的结果
["aa","ab","ac","ba","bb","bc","ca","cb","cc","a","b","c"]
Expected
["aa","ab","ac","ba","bb","bc","ca","cb","cc"]
*/
class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        vector<string> results;
        
        if(digits.empty()) return results;
        
        vector<string> dict; 
        
        dict = vector<string>(10, "");
        
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
                
        dfs(digits, 0, "", results, dict);

        return results;
    }

private:


    
    void dfs(string & s, 
             int start, 
             string current, 
             vector<string> &results, 
             vector<string> &dict) {
                 
        if(current.length() == s.length()) {
            results.push_back(current);
            return;
        }
        
        for(int i = start; i < s.length(); i++) {
            
            if(!isDigit(s[i])) continue;
            
            string s0 = dict[s[i] - '0'];
            
            for(int j = 0; j  < s0.length(); j++) {
                
                current.push_back(s0[j]);
                
                dfs(s, i + 1, current, results, dict);
                
                //backtracking
                current.pop_back();
            }
            
        }
    
        
    }
    
    bool isDigit(char c) {
        if(c >= '2' && c <= '9')
            return true;
        return false;
    }
};