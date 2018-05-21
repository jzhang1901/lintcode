/*
Description

Given a target number, a non-negative integer target and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.
Have you met this question in a real interview?  
Example

Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].
Challenge

O(logn + k) time complexity.

*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        // Setp 1. find the closest postion with O(logn)
        const size_t l = A.size();
        vector<int> ret;
        if(l == 0) return ret;
        if(l == 1) return A;
        if(k == 0) return ret;
        int start = 0; 
        int end = l - 1;
        int closest = 0;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int diff_mid = abs(A[mid] - target);
            int diff_left = abs(A[mid-1] - target);
            int diff_right = abs(A[mid+1] - target);
            
            if(diff_mid == 0) {
                end = mid;
            } else if (diff_left > diff_right){
                start = mid;
            } else {
                end = mid;
            }
        }
        
        int diff_left = abs(A[start] - target);
        int diff_right = abs(A[end] - target);
        
        if (diff_left == 0 || diff_right == diff_left) 
            closest = start;
        else if (diff_right == 0 || diff_right < diff_left) 
            closest = end;
        else
            closest = start;    
            
        ret.push_back(A[closest]);
        
        int left = closest-1;
        int right = closest+1;
        // Step 2: generate the return vector
        for(int i = 0; i < k-1; i++) {
            if(left < 0) {
                ret.push_back(A[right++]);
            } else if(right >= l) {
                ret.push_back(A[left--]);
            } else {
                int diff_left = abs(A[left] - target);
                int diff_right = abs(A[right] - target);
                if(diff_left > diff_right) {
                    ret.push_back(A[right++]);
                } else {
                    ret.push_back(A[left--]);
                }
            }
        }
   
        return ret;
    }
};
