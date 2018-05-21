
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    int partition(vector<int> &A, int start, int end) {
        if(start >= end)
            return end;
        int pivot = A[end];
        int left = start;
        while(left < end) {
            if(A[left] <= pivot) {
                swap(A[start++], A[left]);
            }
            left++;
        }
        swap(A[start], A[end]);
        return start;
    }
    
    void quickSort(vector<int> &A, int start, int end) {
        if (start >= end) return;
        int p = partition(A, start, end);
        quickSort(A, start, p-1);
        quickSort(A, p+1, end);
    }
    void sortIntegers2(vector<int> &A) {
        // write your code here
        const size_t l = A.size();
        if(l <= 1) return;
        quickSort(A, 0, l-1);
    }
};

