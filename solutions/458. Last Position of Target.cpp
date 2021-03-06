/*
Description

Find the last position of a target number in a sorted array. Return -1 if target does not exist.
Have you met this question in a real interview?  
Example

Given [1, 2, 2, 4, 5, 5].

For target = 2, return 2.

For target = 5, return 5.

For target = 6, return -1.
*/

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        const size_t l = nums.size();
        if(l == 0) return -1;
        int start = 0;
        int end = l - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                start = mid; 
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if(nums[end] == target) return end;
        if(nums[start] == target) return start;
        return -1;
    }
};
