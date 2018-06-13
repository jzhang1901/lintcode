/*
Description 664. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
Have you met this question in a real interview?  
Example

Given num = 5 you should return [0,1,1,2,1,2].
Challenge

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

/*
在看了题目的Tag之后在开始想到这个可以用DP来解决
Base case:


Function
if i = 2^k 
    f[n] = 1
else // 2^k + 1 << i < 2^(k+1)
    f[n] = 1 + f[i - 2^k]
Answer:

f[n]

0000 f[0] = 0
0001 f[1] = 1
//　每当数字到了２的几次幂后，就是在之前的状态多了一个最高位１
0010 f[2] = 1 + f[2 - 2 + 0] = 1
0011 f[3] = 1 + f[2 - 2 + 1] = 2
0100 f[4] = 1 + f[4-4 + 0]   = 1
0101 f[5] = 1 + f[4-4 + 1]   = 2
0110 f[6] = 
0111 f[7]
1000 f[8]
*/

 class Solution {
public:
    /**
     * @param num: a non negative integer number
     * @return: an array represent the number of 1's in their binary
     */
    vector<int> countBits(int num) {
        vector<int> f(1+num, 0);
        f[0] = 0;
        f[1] = 1;
        int power2 = 1;
        for(int i = 2; i <= num; i++) {
            if(i/power2 == 2) {
                f[i] = 1;
                power2 = i;
            } else {
                f[i] = 1 + f[i - power2];
            }
        }
        
        return f;
    }
};






