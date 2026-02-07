class MyStack {
public:
    queue<int>que; // Using a single queue to implement stack operations.
    void push(int x) {
        que.push(x); // Push the new element to the back of the queue.
        for(int i=0;i<que.size()-1;i++){
            que.push(que.front()); // Move the front element to the back of the queue to maintain stack order.
            que.pop();
        }
    }
    
    int pop() {
        int val = que.front(); // Get the top element from the stack (front of the queue).
        que.pop(); // Remove the top element from the stack.
        return val;
    }
    
    int top() {
        return que.front(); // Return the top element of the stack without removing it.
    }
    
    bool empty() {
        return que.empty(); // Check if the stack is empty by checking if the queue is empty.
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
// Time Complexity: O(n) for push operation, O(1) for pop, top, and empty operations.
// Space Complexity: O(1) where n is the number of elements in the stack.
