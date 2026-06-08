class MinStack {
public:
    // Implement two stacks 
    // Reasoning : It will always contain only the first element of the stack 
    // For each next element which is smaller than the first element it will push it into the min stack
    // Then it will pop from the min stack
    // Return the element of the top of the min stack 
    // No correct element is missed because if a element was not present in the stack it was never smaller than  the root 
    // Also it correctly follows mootonicity the elements which appear the last get popped the first
    stack <int> stk;
    stack <int> min;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if (stk.empty() || val <= min.top()) min.push(val); 
        stk.push(val);
    }
    
    void pop() {
        if (stk.top() == min.top()) {
            min.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min.top();
    }
};
