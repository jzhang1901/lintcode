/*Description

Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.
Have you met this question in a real interview?  
Example

Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).
Challenge

Do it in O(nlogn) time complexity.
*/
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        const size_t l= nums.size();
        if(l <= 1) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = l-1;
        int gDiff = INT_MAX;
        int gDiffAbs = INT_MAX;
        while(left < right) {
            int localSum = nums[left] + nums[right];
            int localDiff = localSum - target;
            if(localDiff == 0) return 0;
            else if(localDiff > 0) {
                right--;
            } else {
                left++;
            }
            if(abs(localDiff) < gDiffAbs){
                gDiffAbs = abs(localDiff);
                gDiff = abs(localDiff);
            }
        }
        
        return gDiff;
    }
};