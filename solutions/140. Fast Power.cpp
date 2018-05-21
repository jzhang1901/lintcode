/*Description

Calculate the an % b where a, b and n are all 32bit integers.
Have you met this question in a real interview?  
Example

For 231 % 3 = 2

For 1001000 % 1000 = 0
Challenge

O(logn)

*/

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(a == 1) return a % b;
        if(n == 0) return 1%b;
        if(n == 1) return a % b;
        long long temp = fastPower(a, b, n / 2);
        if(n % 2 == 0) {
            return (temp * temp) % b;
        } else {
            return ((temp * temp) % b * a) % b;   
        }
    }
};