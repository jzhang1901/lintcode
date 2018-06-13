/* 642. Moving Average from Data Stream

Description
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Have you met this question in a real interview?  
Example
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000
*/
class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        sum  = 0;
        maxSize = size;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        
        sum = sum + val;  
            
        if(window.size() == maxSize) {
            sum = sum - window.front();    
            window.pop();
        }
        
        window.push(val);

        return sum / window.size();
    }
private:
    queue<int> window;
    double sum;
    int maxSize = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
