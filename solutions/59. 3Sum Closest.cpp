/*
Description

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

You may assume that each input would have exactly one solution.
Have you met this question in a real interview?  
Example

For example, given array S = [-1 2 1 -4], and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Challenge

O(n^2) time, O(1) extra space

*/
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        const size_t l = numbers.size();
        if(l < 3) return 0;
        sort(numbers.begin(), numbers.end());
        int gClosest = INT_MAX;
        int gOpt = INT_MIN;
        int cClosest = INT_MAX;
        for(int right = l - 1; right >= 2; right--) {
            int start = 0;
            int end = right-1;
            while(start < end) {
                int localSum = numbers[start] + numbers[end] + numbers[right];
                int localDiff = localSum - target;
                if(localDiff == 0)
                    return target;
                else if (localSum > target) {
                    end--;
                } else {
                    start++;
                }
                if(abs(localDiff) < gClosest) {
                    gClosest = abs(localDiff);
                    gOpt = localSum;
                }
            }
        }
        return gOpt;
    }
};