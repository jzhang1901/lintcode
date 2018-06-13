/*Description

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
Have you met this question in a real interview?  
Example

Given nums = [-2,0,1,3], target = 2, return 2.

Explanation:
Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]

Challenge

Could you solve it in O(n2) runtime?
*/

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        int nTriplets = 0;
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k) {
                int tripletSum = nums[i] + nums[j] + nums[k];
                if(tripletSum >= target) {
                    k--;
                } else {
                    nTriplets += (k-j);
                    j++;//这里犯错了，　要移动j　这样才能找到所以的case
                }
            }
        }
        return nTriplets;
    }
};