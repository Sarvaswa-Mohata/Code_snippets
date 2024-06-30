class MyQueue {
private:
    stack<int> ip, op;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
       auto it = peek();
       op.pop();
       return it;
    }
    
    int peek() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return op.empty() && ip.empty();
    }
};