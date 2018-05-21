/*
Description

Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.

You do not care about the accuracy of the result, we will help you to output results.
Have you met this question in a real interview?  
Example

Given n = 2 return 1.41421356

*/

class Solution {
public:
    /*
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        double s = 0.0;
        double e = x;
        if(x < 1.0)
            e = 1.0 / x;
        while(s + 1e-10 < e) {
            double mid = (s + e) / 2.0;
            double midS = mid*mid;
            if(abs(midS - x) < 1e-10){
                return mid;
            } else if (midS > x) {
                e = mid;
            } else {
                s = mid;
            }
        }
        
        return (s+e)/2.0;
    }
};