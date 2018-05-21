/*
Description

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
Have you met this question in a real interview?  
Example

add(1); add(3); add(5);
find(4) // return true
find(7) // return false

*/

class TwoSum {
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        ++m[number];
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
       for (const auto &a : m) {
            int t = value - a.first;
            if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;
};

