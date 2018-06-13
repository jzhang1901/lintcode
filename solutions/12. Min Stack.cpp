/*
12. Min Stack
Description

Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.

min operation will never be called if there is no number in the stack.
Have you met this question in a real interview?  
Example

push(1)
pop()   // return 1
push(2)
push(3)
min()   // return 2
push(1)
min()   // return 1


*/

/*
１. 用一个pair 来 存当前的最小和当前值<number, curmin>
２. 每次压栈的时候记录当前的最小值：　比较当前值和栈顶的最小
3.　不可以用一个全局变量 
*/
class MinStack {
public:
    MinStack() {
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        int cur_min = stk.empty() ? number : std::min(number, stk.top().second);
        stk.push(make_pair(number, cur_min));
    }

    /*
     * @return: An integer
     */
    int pop() {
        pair<int, int> cur_top = stk.top();
        stk.pop();
        return cur_top.first;
    }

    /*
     * @return: An integer
     */
    int min() {
        pair<int, int> cur_top = stk.top();
        return cur_top.second;
    }
    
private:
    stack<pair<int, int>> stk;
    int cur_min;
};