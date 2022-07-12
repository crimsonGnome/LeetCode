class MyQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
public:
    MyQueue(){}
    
    void push(int x) {
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);

    }
    
    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int answer = stack2.top();
        stack2.pop();
        return answer;
    }
    
    int peek() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int answer = stack2.top();
        return answer;

    }
    
    bool empty() {
        if(stack1.empty() && stack2.empty()) return true;
        return false;
    }
};