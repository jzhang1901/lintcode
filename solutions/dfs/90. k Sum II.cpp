/*90. k Sum II

Description

Given n unique integers, number k (1<=k<=n) and target.

Find all possible k integers where their sum is target.
Have you met this question in a real interview?  
Example

Given [1,2,3,4], k = 2, target = 5. Return:

[
  [1,4],
  [2,3]
]
*/

解题思路分析：
1. 比较　135. Combination Sum，　这里传的时候需要代入当前还需要多少个数字的信息
2. 要注意什么时候需要退出DFS

Corner case:

class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param targer: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        vector<vector<int>> results;
        
        if(k == 0 || A.empty()) {
            results.push_back({});
            return results;
        }
        vector<int> path;
        sort(A.begin(), A.end());
        dfs(A, 0, k, target, path, results);
        return results;
    }
    
    void dfs(vector<int> &A,
             int start,
             int k, 
             int target, 
             vector<int> path, 
             vector<vector<int>> &results) {
        
        if(target < 0 || k < 0) return;         
        if(target == 0 && k == 0) {
            results.push_back(path);
            return;
        }


        for(int i = start; i < A.size(); i++) {
            path.push_back(A[i]);
            dfs(A, i+1, k-1, target-A[i], path, results);
            path.pop_back();
        }
    }
};
