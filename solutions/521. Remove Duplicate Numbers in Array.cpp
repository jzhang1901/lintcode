/*
Description

Given an array of integers, remove the duplicate numbers in it.

You should:

    Do it in place in the array.
    Move the unique numbers to the front of the array.
    Return the total number of the unique numbers.

You don't need to keep the original order of the integers.
Have you met this question in a real interview?  
Example

Given nums = [1,3,1,4,4,2], you should:

    Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
    Return the number of unique integers in nums => 4.

Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.
Challenge

    Do it in O(n) time complexity.
    Do it in O(nlogn) time without extra space.


*/

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        const size_t l = nums.size();
        if(l <= 1) return l;
        unordered_map<int, bool> hash;
        int leftPos = 1;
        hash[nums[0]] = true; 
        for(int right = 1; right < l; right++) {
            if(hash.find(nums[right]) == hash.end()) {
                nums[leftPos] = nums[right];
                hash[nums[right]] = true;
                leftPos++;
            }
        }
        return leftPos;
    }
};


class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        const size_t l = nums.size();
        if(l <= 1) return l;
        sort(nums.begin(), nums.end());
        
        int leftPos = 1;
        for(int right = 1; right < l; right++) {
            if(nums[right] != nums[right-1]) {
                nums[leftPos++] = nums[right];
            }
        }
        return leftPos;
    }
};
