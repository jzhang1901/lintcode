/*
Description

Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. Please return the number of pairs.
Have you met this question in a real interview?  
Example

Given nums = [2, 7, 11, 15], target = 24.
Return 5.
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25


*/
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        const size_t l= nums.size();
        if(l <= 1) return 0;
        sort(nums.begin(), nums.end(), std::greater<int>());
        int ret = 0;
        int start = 0;
        int end = l-1;
        while(start < end) {
            int localSum = nums[start] + nums[end];
            if(localSum > target) {
                start++;
            } else {
                ret += (end - start);
                end--;
            }
        }
        return ret;
    }
};