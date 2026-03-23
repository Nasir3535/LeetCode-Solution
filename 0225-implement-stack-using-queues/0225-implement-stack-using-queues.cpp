class MyStack {
public:
    MyStack() {

        
    }
    
    void push(int x) {
        auxiliary_queue.push(x);
      
        
        while (!main_queue.empty()) {
            auxiliary_queue.push(main_queue.front());
            main_queue.pop();
        }
      
        swap(main_queue, auxiliary_queue);

    }
    
    int pop() {
        int top_element = main_queue.front();
        main_queue.pop();
        return top_element;
    }
    
    int top() {
        return main_queue.front();
    }
    
    bool empty() {
        return main_queue.empty();
    }
private:
    queue<int> main_queue;      
    queue<int> auxiliary_queue; 

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
