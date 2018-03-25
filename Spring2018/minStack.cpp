class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> *stack;
    vector<int> *minStack;
    //static int topE;
     int min;
    MinStack() {
        //topE = -1;
        stack = new vector<int>();
        minStack = new vector<int>();
        min = INT_MAX;
    }
    
    void push(int x) {
        stack->push_back(x);
        if (minStack->size() == 0) {
        if (x <= min)
        {
            minStack->push_back(x);
        }
        }
        else
        {
         if (x <= minStack->back())
        {
            minStack->push_back(x);
        }   
        }
        //topE++;
    }
    
    void pop() {
        
        
        int temp = stack->back();
        if (temp <= minStack->back())
            minStack->pop_back();
        stack->pop_back();
       // topE--;
    }
    
    int top() {
        return stack->back();
    }
    
    int getMin() {
        return minStack->back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
