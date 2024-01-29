class MyQueue {
public:
   stack<int> s1;
    MyQueue() {
        
    }


    void push_in_stack(int x){
          if(s1.size()==0){
              s1.push(x);
              return;
          }

          int val = s1.top();
          s1.pop();
          push_in_stack(x);
          s1.push(val);
    }
    
    void push(int x) {
         push_in_stack(x);
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
         return s1.top();
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};


