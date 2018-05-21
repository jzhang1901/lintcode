/*
Description

Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.
Have you met this question in a real interview?  
Example

Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10
*/

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        const size_t l = nums.size();
        if(l == 0) return INT_MIN;
        if(l == 1) return nums[0];
        int start = 0;
        int end = l -1;
        while(start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return nums[mid];
            } else if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                start = mid;
            } else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if(nums[start] > nums[end]) return nums[start];
        return nums[end];
    }
};