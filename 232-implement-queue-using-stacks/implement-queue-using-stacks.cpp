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
        if(!op.empty()){
            auto it = op.top();
            op.pop();
            return it;
        }
        int it;
        while(!ip.empty()){
            it = ip.top();
            op.push(it);
            ip.pop();
        }
        it=op.top();
        op.pop();
        return it;
    }
    
    int peek() {
        if(!op.empty()){
            return op.top();
        }
        int it;
        while(!ip.empty()){
            it=ip.top();
            op.push(it);
            ip.pop();
        }
        return op.top();
    }
    
    bool empty() {
        return op.empty() && ip.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */