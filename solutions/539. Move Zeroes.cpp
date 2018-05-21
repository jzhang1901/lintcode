/*
Description

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

Have you met this question in a real interview?  
Example

Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        const size_t l = nums.size();
        if(l <= 1) return;
        int left = 0;
        int right = left;
        for(int right = 0; right < l; right++) {
            if(nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};