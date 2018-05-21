/*
Description

Given an array of integers, find two numbers that their difference equals to a target value.
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

It's guaranteed there is only one available solution
Have you met this question in a real interview?  
Example

Given nums = [2, 7, 15, 24], target = 5
return [1, 2] (7 - 2 = 5)

*/

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        const size_t l = nums.size();
        vector< pair <int,int> > A;
        vector<int> ret;
        for (int i=0; i<l; i++)
            A.push_back(make_pair(nums[i], i));
                
        if(l <= 1) return ret;
        sort(A.begin(), A.end()); // sort by first key
        int s = 0;
        int e = s+1;
        while(e < l) {
            int diff = A[e].first - A[s].first;
            if(diff == abs(target)) {
                int idx1 = A[s].second+1;
                int idx2 = A[e].second+1;
                if(idx1 > idx2) swap(idx1, idx2);
                ret.push_back(idx1);
                ret.push_back(idx2);
                return ret;
            } else if (diff > abs(target)) {
                s++;
                while (s >= e) e++;
            } else {
                e++;
            }
        }
        
        return ret;
    }
};