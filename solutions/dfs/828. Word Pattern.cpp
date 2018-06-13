/* 828. Word Pattern
Description
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Have you met this question in a real interview?  
Example
Given pattern = "abba", str = "dog cat cat dog", return true.
Given pattern = "abba", str = "dog cat cat fish", return false.
Given pattern = "aaaa", str = "dog cat cat dog", return false.
Given pattern = "abba", str = "dog dog dog dog", return false.

*/
解题思路：这题非常简单，但是居然做错两个地方
Takeaways:
1. 用stringstream和getline()　分割比较高效
2. 要检查当前string 是不是已经被之前什么char match过了 


#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution2 {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param str: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &str) {
        
        stringstream ss (str);
        string key;
        char delimiter = ' ';
        int pIndex = 0;
        
        set<string> used;
        map<char, string> hash;
        
        
        for(int i = 0; i < pattern.length(); i++) {
            if(!getline(ss, key, delimiter)) return false;
            
            char curChar = pattern[i];
            
            if(hash.count(curChar)) {
                
                if(hash[curChar] != key) return false;
                
            } else {
                
                if(used.count(key)) return false;
                
                hash[curChar] = key;
                used.insert(key);
            }
        }
        
        //　如果不能再提取出新的key　那么就是match
        return !getline(ss, key, delimiter);
    }
};

class Solution {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param str: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &str) {
        
        map<char, string> hash;
        set<string> used;

        int start = 0;

        for(int i = 0; i < pattern.length(); i++) {
            
            char c = pattern[i];
            
            string s = getNextString(str, start);
            // std::cout << start << ":";
            // std::cout << s << std::endl;

            if(hash.count(c)) {
                if(hash[c] != s) return false;
            } else {
                if(used.count(s)) return false;
                used.insert(s);
                hash[c] = s;
            }
            //错误１
            start += (s.length() + 1);
        }
        
        if(start >= str.length()) return true;
        
        return false;
    }
    
    string getNextString(const string &s, int start) {
        
        while(start < s.length() && isspace(s[start])) start++;
        
        int len = 0;
        for(int i = start; i < s.length(); i++) {
            if(isspace(s[i])) break;
            len++;
        }
        
        return s.substr(start, len);
    }
};



