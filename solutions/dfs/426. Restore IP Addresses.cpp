/* 426. Restore IP Addresses
Description
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Have you met this question in a real interview?  Yes
Example
Given "25525511135", return

[
  "255.255.11.135",
  "255.255.111.35"
]
Order does not matter.
*/

class Solution {
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        
        vector<string> results;
       
        // Need at least 4 digits in the string
        if(s.empty() || s.length() < 4) return results; 
        
        vector<string> current;
        
        dfs(s, 0, current, results);
        
        return results;
    }
    
    
    void dfs(string &s, 
             int start, 
             vector<string> current, 
             vector<string> &results) {
        
        if(start >= s.length()) {

            if(current.size() == 4) {

                string s = current[0] + "." + 
                           current[1] + "." + 
                           current[2] + "." + 
                           current[3];

                results.push_back(s);
            }
            return;
        }
        // This is to prevent 00 case
        int end = s[start] == '0' ? start : s.length();

        for(int i = start; i < s.length(); i++) {
            
            const int l0 = i - start + 1;
            string s0 = s.substr(start, l0);
            
            int number = convertToNumber(s0);
            if(number < 0) continue;
            if(number > 255) return;
            if(current.size() >= 4) return;
            current.push_back(s0);
            dfs(s, start + l0, current, results);
            current.pop_back();
        }
    }
    
    int convertToNumber(string &s) {
        if(s.empty()) return -1;
        
        int num = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }   
        }
        return num;
    }
};