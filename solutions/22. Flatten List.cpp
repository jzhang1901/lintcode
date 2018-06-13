/*
Description

Given a list, each element in the list can be a list or integer. flatten it into a simply list with integers.

If the element in the given list is a list, it can contain list too.
Have you met this question in a real interview?  
Example

Given [1,2,[1,2]], return [1,2,1,2].

Given [4,[3,[2,[1]]]], return [4,3,2,1].
Challenge

Do it in non-recursive.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(const vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> ret;
        if(nestedList.empty()) return ret;
        for(const auto & item : nestedList) {
            if(item.isInteger())
                ret.push_back(item.getInteger());
            else {
                const vector<int> ret2 = flatten(item.getList());
                ret.insert(std::end(ret), std::begin(ret2), std::end(ret2));
            }
        }
    }
};