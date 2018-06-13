/*Description 18. Subsets II

Given a list of numbers that may has duplicate numbers, return all possible subsets

    Each element in a subset must be in non-descending order.
    The ordering between two subsets is free.
    The solution set must not contain duplicate subsets.

Have you met this question in a real interview?  
Example

If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Challenge

Can you do it in both recursively and iteratively?
*/
// 至少有四个点容易犯错
//1. 如果没有数字需要至少返回一个空集      
//2. 需要对原数值排序，以方便检测重复
//3. 注意每个节点都是结果，　不需要start >= size
//4.注意这里对重复的处理


class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> results;
        vector<int> subset;
        //1. 如果没有数字需要至少返回一个空集
        if(nums.empty()) {
            results.push_back(subset);
            return results;
        }
        //2. 需要对原数值排序，以方便检测重复
        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, results);
        
        return results;
    }
    
private:
    void dfs(vector<int> &nums, 
             int start, 
             vector<int>subset, 
             vector<vector<int>> &results) {
    
        //3. 注意每个节点都是结果，　不需要start >= size
        results.push_back(subset);
  
        
        for(int i = start; i < nums.size(); i++) {
  
            if(i > start && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            dfs(nums, i+1, subset, results);
            subset.pop_back();
        }
    }
};
