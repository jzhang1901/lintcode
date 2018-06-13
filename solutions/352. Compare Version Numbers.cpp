/*

352. Compare Version Numbers
Description

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Have you met this question in a real interview?  
Example

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <string>
#include <iostream>

using namespace std;

long long isPalindrome(int num) {
    // write your code here
    long long rnum = 0;
    while(num) {
        int remain = num % 10;
        rnum = rnum * 10 + remain;
        num /= 10;
    }
    
    return rnum;
}

string parseString(string &str) {
    const size_t len = str.length();
    int backSpaceCnt = 0;
    int rightPos = len-1;

    int n = 0;
    for(int i = len-1; i >= 0; i--) {
        if(str[i] == '<') {
            backSpaceCnt++;
            std::cout << "backSpaceCnt " << backSpaceCnt << '\n';
        } else if(backSpaceCnt == 0) {
            str[rightPos--] = str[i];
            cout << i  << "=>" << rightPos << endl; 
        } else if(backSpaceCnt > 0) {
            backSpaceCnt--;
        }
    }
    cout << rightPos <<endl;
    return str.substr(rightPos+1);
}

class Solution {
public:
    /**
     * @param version1: the first given number
     * @param version2: the second given number
     * @return: the result of comparing
     */
    int getNextSubversion(string &v, int &pos) {
        if(pos >= v.length()) return 0;
        
        int dotPos = v.length();
        for(int i = pos; i < v.length(); i++) {
            if(v[i] == '.') {
                dotPos = i;
                break;
            }
        }
        
        if(dotPos == 0) {
            pos = dotPos + 1;
            return 0;
        }
        
        int version = 0;
        while(v[pos] == '0') pos++;
        for(int i = pos; i <= dotPos-1; i++) {
            version = version * 10 + (v[i] - '0');
        } 
        std::cout << v << std::endl;
        std::cout << "[ " << pos << "," << dotPos << " ]"<< std::endl;
        pos = dotPos + 1;
        return version;
    }

    int compareVersion(string &version1, string &version2) {
        const int l1 = version1.length();
        const int l2 = version2.length();
        int i = 0, j = 0;
        while(i < l1 && j < l2) {
            int v1 = getNextSubversion(version1, i);
            int v2 = getNextSubversion(version2, j);
            std::cout << "v1: " <<  v1 << std::endl;
            std::cout << "v2: " <<  v2 << std::endl;

            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        
        if(i >= l1 && j >= l2) return 0;
        
        while(i < l1) {
            if(getNextSubversion(version1, i) != 0)
                return 1;
        } 
        
        while(j < l2) {
            if(getNextSubversion(version2, j) != 0)
                return -1;
        } 
        return 0;
    }

};