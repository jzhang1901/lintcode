/*
Description

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
Have you met this question in a real interview?  
Example

For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.
Challenge

O(logN) time
*/

class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        const size_t l = A.size();
        if(l <= 0) return -1;
        int start = 0;
        int end = l - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] == target) 
                return mid;
            if(A[start] < A[mid]) {
                if(A[start] <= target && A[mid] >= target) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                // from mid to end, increasing
                if(A[end] >= target && A[mid] <= target) {
                    start = mid;
                } else {
                    end = mid;
                }   
            }
        }
        
        if(A[start] == target) return start;
        if(A[end] == target) return end;
        
        return -1;
    }
};
