/* 136. Palindrome Partitioning
Description
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Have you met this question in a real interview?  Yes
Example
Given s = "aab", return:

[
  ["aa","b"],
  ["a","a","b"]
]
*/
// 解题分析
// 经典DFS问题
// 尝试每一刀的位置,比较容易犯错的是for loop里面什么时候循环截止

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        
        vector<vector<string>> results;
        vector<string> partitions; 
        
        if(s.empty()) return results;
        // the first possible cut position is 0
        // the last possible cut position is s.length() -2
        dfs(s, 0, partitions, results);
        
        
        return results;
    }
    
    void dfs(string &s, 
             int pos, 
             vector<string> &partitions, 
             vector<vector<string>> &results) {
        // 如果当前
        if(pos >= s.length()) {
            results.push_back(partitions);
            return;
        }
        
        for(int i = pos; i < s.length(); i++) {
            
            // pick a substr starting from pos with size 1, 2,...
            const int s0Len = i-pos+1;
            
            string s0 = s.substr(pos, s0Len);
            
            if(!isPalindrome(s0)) continue;
            
            partitions.push_back(s0);
            
            dfs(s, pos + s0Len, partitions, results);
            
            partitions.pop_back();
        }
    }
    
    
    // Can be optimized by using DP and a table
    bool isPalindrome(string &s) {
        
        int end = s.length() -1;
        
        int start = 0;
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
};