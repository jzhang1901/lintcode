/*
Description

Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

You couldn't cut wood into float length.

If you couldn't get >= k pieces, return 0.
Have you met this question in a real interview?  
Example

For L=[232, 124, 456], k=7, return 114.
Challenge

O(n log Len), where Len is the longest length of the wood.
*/

class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        const size_t l = L.size();
        if(l == 0) return 0;
    
        int maxWoodLen = L[0];
        for(int i = 1; i < l; i++)
            maxWoodLen = max(maxWoodLen, L[i]);
        if(k <= 1) return maxWoodLen;
        int start = 0;
        int end = maxWoodLen;
        int maxCutLen = 0;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if(isValidCut(L, k, mid)) {
                maxCutLen = max(maxCutLen, mid); 
                start = mid; 
            } else {
                end = mid;
            }
        }
        
        if(isValidCut(L, k, end)) return end;
        if(isValidCut(L, k, start)) return start;
    
        return maxCutLen;
    }
    
    bool isValidCut(vector<int> &L, int k, int cutLen) {
        int totCut = 0;
        if(cutLen == 0) return false;
        for(int i = 0; i < L.size(); i++) {
            totCut += (L[i] / cutLen);
        }
        return totCut >= k;
    }
};