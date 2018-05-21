/*
Description

Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.
Have you met this question in a real interview?  
Example

Given numbers = [2, 7, 11, 15], target = 24. Return 1. (11 + 15 is the only pair)
Challenge

Do it in O(1) extra space and O(nlogn) time.

*/
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // write your code here
        const size_t l= nums.size();
        if(l <= 1) return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        int start = 0;
        // fix the right position
        for(int right = l - 1; right >= 1; right--) {
            while(start < right) {
                if(nums[start] + nums[right] <= target) {
                    start++;
                } else {
                    ret += (right - start);
                    break;
                }
            }
        }
        return ret;
    }
};

class Solutio2 {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        const int length = nums.size();
        if(length < 2) return 0;
            
        int start = 0;
        int end   = length - 1;
        int res = 0;
        sort(nums.begin(), nums.end());
    
        while(start < end) {
            if(nums[start] + nums[end] <= target) {
                start++;
            } else {
                res = res + (end - start);
                end--;
            }
        }
        return res;
    }
};