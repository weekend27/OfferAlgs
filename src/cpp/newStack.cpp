class Solution {
public:

    stack<int> numStack;
    stack<int> minStack;

    void push(int value) {

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }

        numStack.push(value);

    }
    void pop() {

        if (numStack.top() == minStack.top()) {
            minStack.pop();
        }

        numStack.pop();

    }
    int top() {

        return numStack.top();

    }
    int min() {

        return minStack.top();

    }
};
