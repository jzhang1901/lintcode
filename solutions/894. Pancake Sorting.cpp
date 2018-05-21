/*
Description

Given an an unsorted array, sort the given array. You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i 

Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

You only call flip function.
Don't allow to use any sort function or other sort methods.

Java：you can call FlipTool.flip(arr, i)
C++： you can call FlipTool::flip(arr, i)
Python2&3 you can call FlipTool.flip(arr, i)
Have you met this question in a real interview?  
Example

Given array = [6, 7, 10, 11, 12, 20, 23]
Use flip(arr, i) function to sort the array.

*/

/**
 * class FlipTool {
 * public:
 *   static void flip(vector<int>& arr, int i);
 * };
 */
class Solution {
public:
    /**
     * @param array: an integer array
     * @return: nothing
     */
    void pancakeSort(vector<int> &array) {
        // Write your code here
        FlipTool ft;
        const int l = array.size();
        if(l <= 1) return;
        int s = 0;
        int e = l-1;
 
        while(e >= 1) {
            int curMaxIndex = 0;
            int curMax = array[0];
            for(int i = 1; i <= e; i++) {
                if(array[i] > curMax) {
                    curMax = array[i];
                    curMaxIndex = i;
                }
            }
           // flip 0 -> curMaxIndex
            ft.flip(array, curMaxIndex);
            ft.flip(array, e);
            e--;
        }
    }
};