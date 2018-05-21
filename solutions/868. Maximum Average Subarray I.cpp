/*
Description

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

    1 <= k <= n <= 30,000.
    Elements of the given array will be in the range [-10,000, 10,000].

Have you met this question in a real interview?  
Example

Given nums = [1,12,-5,-6,50,3], k = 4, return 12.75.

Explanation:
Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
*/

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        // Write your code here
        double maxAS = 0.0;
        const size_t l = nums.size();
        if(l == 0) return maxAS;
        double curSum = 0;
        for(int i = 0; i < k && i < l; i++)
            curSum += nums[i];
        maxAS = curSum / (double)k;
        for(int i = k; i < l; i++) {
            curSum += (nums[i] - nums[i - k]);
            maxAS = max(maxAS, curSum / k);
        }
        return maxAS;
    }
};