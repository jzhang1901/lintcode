/*
Description

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
Example

Given the string = "abcdzdcab", return "cdzdc".
Challenge

O(n2) time is acceptable. Can you do it in O(n) time.
*/

class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        const int l = s.length();
        string ret;;
                
        std::vector<vector<bool>> f(l, vector<bool>(l, false));
        for(int i = 0; i < l; i++) {
                f[i][i] = true;
                ret = s[0];
        }

        for(int i = 0; i < l-1; i++) {
            if(s[i] == s[i+1]) {
                f[i][i+1] = true;
                ret = s.substr(i, 2);              
            }
        }

        bool prevLoopHasPalindrome = true;
        

        for(int interval = 2; interval < l; interval++) {
            bool currLoopHasPalindrome = false ;
            for(int start = 0; start + interval < l; start++) {
                int end = start + interval;
                
                if(s[start] == s[end] && f[start+1][end-1]) {
                    f[start][end] = true;
                    currLoopHasPalindrome = true;
                    ret = s.substr(start, interval+1);
                }
            }
            if(!currLoopHasPalindrome && !prevLoopHasPalindrome) {
                break;
            }
            prevLoopHasPalindrome = currLoopHasPalindrome;
    
        }
        return ret;
    }
};