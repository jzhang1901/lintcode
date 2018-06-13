/*
Description

Given an integer arrays, find a contiguous subarray which has the largest sum and length should be greater or equal to given length k.
Return the largest sum, return 0 if there are fewer than k elements in the array.

Ensure that the result is an integer type.
Have you met this question in a real interview?  
Example

Given the array [-2,2,-3,4,-1,2,1,-5,3] and k = 5, the contiguous subarray [2,-3,4,-1,2,1] has the largest sum = 5.

*/

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param k: an integer
     * @return: the largest sum
     */
    int maxSubarray4(vector<int> &nums, int k) {
        // write your code here
        const size_t l = nums.size();
        if (l < k) return 0;
        vector<int> prefix(l+1, 0);
        int minPrev = 0;
        int maxSumK = INT_MIN;
        prefix[0] = 0;
        for(int i = 1; i <= l; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
            if(i >= k) {
                maxSumK = max(maxSumK, prefix[i] - minPrev);
                // update minPrev
                minPrev = min(minPrev, prefix[i-k+1]); // Made a mistake here between i-k+1 and i-k
            }
        }
        
        return maxSumK;
    }
};