/*
Description

Prime factorize a given integer.

You should sort the factors in ascending order.
Have you met this question in a real interview?  
Example

Given 10, return [2, 5].

Given 660, return [2, 2, 3, 5, 11].

*/

class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        // write your code here
        vector<int> ret;
        if(num <= 1) return ret;
        int end = sqrt(num);
        for(int i = 2; i <= end && num > 1; i++) {
            while(num % i == 0) {
                num /= i;
                ret.push_back(i);                
            }
        }
        if(num > 2) {
            ret.push_back(num);
        }
        return ret;
    }
};
