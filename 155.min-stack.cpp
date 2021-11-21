/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<long long > s;
    long long  minElement = 1e18;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(long long  val) {
        if(s.empty()){
            s.push(val);
            minElement = val;
        }
        else{
            if(val<minElement){
                s.push(2*val-minElement);
                minElement = val;
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.empty())
            return ;
        long long  x =  s.top();
        s.pop();
        if(x<minElement){
            minElement = 2*minElement - x;
        }
    }

    
    int top() {
        
        if(s.empty())
            return -1;
        long long  x =  s.top();
        if(x<minElement){
            return minElement;
        }

        return x;
            
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object wilong long  be instantiated and calong long ed as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long long  param_3 = obj->top();
 * long long  param_4 = obj->getMin();
 */
// @lc code=end

