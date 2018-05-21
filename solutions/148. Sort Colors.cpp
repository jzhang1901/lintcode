/*
Description

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

You are not suppose to use the library's sort function for this problem.
You should do it in-place (sort numbers in the original array).
Have you met this question in a real interview?  
Example

Given [1, 0, 1, 2], sort it in-place to [0, 1, 1, 2].
Challenge

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/
class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size <= 0)
            return;
        
        int left = 0;
        int right = size -1 ;
        int cur = 0;
        
        while(cur <= right) {
            if(nums[cur] == 0) {
                swap(nums[left++], nums[cur++]);
            } 
            else if(nums[cur] == 1) {
                cur++;
            }
            else {
                swap(nums[right--], nums[cur]); // make a mistake here
            }
            
        }
        
    }
};
