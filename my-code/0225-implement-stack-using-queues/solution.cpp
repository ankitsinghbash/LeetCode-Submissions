class MyStack {
public:
    //implement using one queue:
    queue<int> qu;
    MyStack() {
        
    }
    
    void push(int x) {
         qu.push(x);
         for(int i=0;i<qu.size()-1;i++){
             int val = qu.front();
             qu.pop();
             qu.push(val);
         }
    }
    
    int pop() {
        int value = qu.front();
        qu.pop();
        return value;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
