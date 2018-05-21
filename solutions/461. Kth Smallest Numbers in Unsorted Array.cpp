/*
Description

Find the kth smallest numbers in an unsorted integer array.
Have you met this question in a real interview?  
Example

Given [3, 4, 1, 2, 5], k = 3, the 3rd smallest numbers are [1, 2, 3].
Challenge

An O(nlogn) algorithm is acceptable, if you can do it in O(n), that would be great.

*/

class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        const size_t l = nums.size();
        if(l == 0) return INT_MIN;
        return quickSelectKthSmallest(nums, 0, l-1, k-1);
    }
    
    int quickSelectKthSmallest(vector<int> &A, int start, int end, int k) {
        int left = start, right = end;
        int mid = (start+end) / 2;
        if(start == end) return A[start];
        int pivot = A[mid];
        
        while(left <= right) {
            while(left <= right && A[left] < pivot) left++;
            while(left <= right && A[right] > pivot) right--;
            // swap 
            if(left <= right) {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        }
        if(start <= right && right>= k) {
            return quickSelectKthSmallest(A, start, right, k);
        } else if(left <= end && left <= k) {
            return quickSelectKthSmallest(A, left, end, k);
        } else  
            return A[k];
    }
};