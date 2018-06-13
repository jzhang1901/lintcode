
/*
831. 3Sum II
Description

Given n, find the number of solutions for all x, y, z that conforms to x^2+y^2+z^2 = n.(x, y, z are non-negative integers)

    n <= 1000000
    x, y, z satisfy (x <= y <= z), we can consider that is the same solution as long as the three numbers selected are the same
*/
class Solution {
public:
    /**
     * @param n: an integer
     * @return: the number of solutions
     */
    int threeSum2(int n) {
        if(n == 0) return 1;
        
        int nCounter = 0;
        int m = (int)sqrt(n); //　这里比较容易出现问题，　如果不去sqrt,　计算结果会interger overflow 
        while(m*m > n) m--;
        for(int x = 0; x < m; x++) {
            int target = n - x*x;
            if(target < 0)
                break;
            int y = x, z = m;
            while(y <= z) {
                int y2plusz2 = y*y + z*z;
                if(y2plusz2 == target) {
                    nCounter++;
                    y++;// 如果 当前 y　和 z　满足要求，那么我们增加y　即可
                } else if (y2plusz2 > target) {
                    z--;
                } else {
                    y++;
                }
            }
            
        }
        return nCounter;
    }
};