class Stack {
public:
    // Push element x onto stack.
    queue<int> q1, q2;
    bool q2top;
    
    void moveQ(queue<int>& que1, queue<int>& que2, int num){
        if(num <= 0) return;
        for(int i = 0; i < num; i ++){
            que2.push(que1.front());
            que1.pop();
        }
    }
    
    
    Stack(){
        q2top = false;
    }
    
    void push(int x) {
        if(q2top){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(empty()) return;
        if(q2top){
            moveQ(q2, q1, q2.size() - 1);
            q2.pop();
        }else{
            moveQ(q1, q2, q1.size() - 1);
            q1.pop();
        }
        q2top = !q2top;
    }

    // Get the top element.
    int top() {
        if(q1.size() + q2.size() == 0) return 0;
        int tmp;
        if(q2top){
            moveQ(q2, q1, q2.size() - 1);
            tmp = q2.front();
            moveQ(q2, q1, 1);
        }else{
            moveQ(q1, q2, q1.size() - 1);
            tmp = q1.front();
            moveQ(q1, q2, 1);
        }
        q2top = !q2top;
        return tmp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.size() + q2.size() == 0 ;
    }
};
