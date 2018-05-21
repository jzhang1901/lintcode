/*
Description

Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?
Have you met this question in a real interview?  
Example

Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]

Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
*/
class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        const int l = S.size();
        
        if(l < 3) return 0;
        sort(S.begin(), S.end());
        
        int res = 0;
        for(int k = l - 1; k >= 2; k--)
        {
            int target = S[k];
            
            int start = 0;
            int end   = k - 1;
            
            while(start < end) {
                if(S[start] + S[end] <= target) {
                    start++;
                } else { //if(S[start] + S[end] > target), all the pairs between start and end are valid
                    res = res + (end - start);
                    end--;
                }
            }
        }
        return res; 
    }
};
