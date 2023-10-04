class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        int popElement;
        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            popElement = q1.front();
            q1.pop();
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            popElement = q2.front();
            q2.pop();
        }
        return popElement;
    }
    
    int top() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        else if(!q1.empty()){
            return q1.back();
        }
        else{
            return q2.back();
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        else{
            return false;
        }
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