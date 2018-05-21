/*
Description

Partition an unsorted integer array into three parts:

    The front part < low
    The middle part >= low & <= high
    The tail part > high

Return any of the possible solutions.

low <= high in all testcases.
Have you met this question in a real interview?  
Example

Given [4,3,4,1,2,3,1,2], and low = 2 and high = 3.

Change to [1,1,2,3,2,3,4,4].

([1,1,2,2,3,3,4,4] is also a correct answer, but [1,2,1,2,3,3,4,4] is not)
Challenge

    Do it in place.
    Do it in one pass (one loop).


*/

class Solution {
public:
    /*
     * @param nums: an integer array
     * @param low: An integer
     * @param high: An integer
     * @return: 
     */
    void partition2(vector<int> &nums, int low, int high) {
        // write your code here
        const size_t l = nums.size();
        int s = 0;
        int e = l-1;
        for(int c = 0; c < l; c++) {
            if(nums[c] < low) {
                swap(nums[c], nums[s++]);
            } else if (nums[c] > high) {
                swap(nums[c], nums[e--]);
            }
            if(s >= e)
                break;
        }
    }
};