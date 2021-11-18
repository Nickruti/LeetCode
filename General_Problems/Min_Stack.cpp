/*
url - https://leetcode.com/problems/min-stack/
*/
class MinStack {
public:
    stack<int> mystack;
    int minV = INT_MAX;
    
    MinStack() {
    }
    
    void push(int val) {
        if (minV >= val)
        {
            mystack.push(minV);
            minV = val;
        }
        mystack.push(val);    
    }
    
    void pop() {
        if (minV == mystack.top())
        {
            mystack.pop();
            minV = mystack.top();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return minV;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
