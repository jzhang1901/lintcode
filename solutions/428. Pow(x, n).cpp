/*
Implement pow(x, n).

You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.

*/
// Note: INT_MAX = 0x7ffffff
// INT_MIX = 0 - (INT_MAX + 1);

class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPowHelper(double x, int n) {
        // write your code here
        if(x == 0) return 0;
        if(n == 1) return x;
        if(x != 0 && n == 0) return 1;
        double temp = myPow(x, n/2);
        if( n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * x;
        }
    }
    double myPow(double x, int n) {
        // write your code here
        double ret;
        int abs_n = 0;
        if(n == INT_MIN)
            abs_n = INT_MAX;
        else
            abs_n = n;
        ret = myPowHelper(x, abs(abs_n));
        if(n < 0) {
            double temp = 1.0 / ret;
            if(n == INT_MIN)
                return temp / x; 
            else
                return temp;
        }
        return ret;
    }  
    
};

