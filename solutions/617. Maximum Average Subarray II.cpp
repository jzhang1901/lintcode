/*Description

Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

It's guaranteed that the size of the array is greater or equal to k.
Have you met this question in a real interview?  
Example

Given nums = [1, 12, -5, -6, 50, 3], k = 3

Return 15.667 // (-6 + 50 + 3) / 3 = 15.667
*/
class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    bool isValidAverage(vector<int> &nums, int k, double estAvg) {
        const size_t l = nums.size();
        vector<double> prefix(l+1, 0.0);
        double prevKMin = 0;
        for(int i = 1; i < l+1; i++) {
            prefix[i] = prefix[i-1] + (nums[i-1] - estAvg);
            if(i >= k) {
                if(prefix[i] - prevKMin >= 0.0) return true;
                prevKMin = min(prevKMin, prefix[i+1-k]);
            }
        }
        return false;
    }
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        int arrMin = INT_MAX;
        int arrMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            arrMax = max(arrMax, nums[i]);
            arrMin = min(arrMin, nums[i]);
        }
        
        double start = arrMin, end =  arrMax;
        while (start + 1e-6 < end) {
            double estAvg = start + (end - start) / 2.0;
            if(isValidAverage(nums, k, estAvg)) {
                start = estAvg;
            } else {
                end = estAvg;
            }
        }
        if(isValidAverage(nums, k, end)) return end;
        return start;
    }
};