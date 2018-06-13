/*Description

Given n books and the ith book has A[i] pages. You are given k people to copy the n books.

n books list in a row and each person can claim a continous range of the n books. For example one copier can copy the books from ith to jth continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).

They start copying books at the same time and they all cost 1 minute to copy 1 page of a book. What's the best strategy to assign books so that the slowest copier can finish at earliest time?
Have you met this question in a real interview?  
Example

Given array A = [3,2,4], k = 2.

Return 5( First person spends 5 minutes to copy book 1 and book 2 and second person spends 4 minutes to copy book 3. )
*/

class Solution {
public:
    int copyBooksHelper(vector<int> &pages, int amount, int &segMax) {
        int numCopier = 0;
        int curSum = 0;
        segMax = INT_MIN;
        // Note: for [3,2,4], amount 4, and 5 has the same numCopier
        // so we need segMax to tell us which one is tigher
        for(int i = 0; i < pages.size(); i++) {
            curSum += pages[i];
            if(curSum >= amount) {
                if(curSum == amount) {
                    curSum = 0;
                    segMax = max(segMax, amount);
                }
                else {
                    segMax = max(segMax, curSum -pages[i]);
                    curSum = pages[i];
                }
                numCopier++;
            }
        }
        if(curSum && curSum <= amount) numCopier++;
        return numCopier;
    }
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int minPages = INT_MIN;
        int maxPages = 0;
        if(pages.size() == 0) return 0;
        if(k == 0) return 0;
        for(int i = 0; i < pages.size(); i++) {
            minPages = max(minPages, pages[i]);
            maxPages += pages[i];
        }
        int prev = 0;
        if(k >= pages.size()) return minPages;
        int start = minPages, end = maxPages;
    
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int segMax;
            if(copyBooksHelper(pages, mid, segMax) > k) { // mid too small
                start = mid;
            } else{
                end = mid;
            }
        }
        
        int segMax = INT_MIN;
        if(copyBooksHelper(pages, end, segMax) == k)  {
            if(end == segMax) return end;
        };        
        if(copyBooksHelper(pages, start,segMax ) == k) {
            if(start == segMax) return start;
        };        
        return segMax;
    }
    

};