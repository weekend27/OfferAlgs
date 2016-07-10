import java.util.Stack;

public class Solution {

    Stack<Integer> stackData = new Stack<>();
    Stack<Integer> stackMin = new Stack<>();


    public void push(int node) {
        stackData.push(node);
        if (stackMin.empty()) {
            stackMin.push(node);
        } else {
            if (node <= stackMin.peek()) {
                stackMin.push(node);
            }
        }
    }

    public void pop() {
        if (stackData.empty()) {
            throw new RuntimeException("Stack is empty!");
        }
        int val = stackData.pop();
        if (val == stackMin.peek()) {
            stackMin.pop();
        }
    }

    public int top() {
        if (stackData.empty()) {
            throw new RuntimeException("Stack is empty!");
        }
        return stackData.peek();
    }

    public int min() {
        if (stackMin.empty()) {
            throw new RuntimeException("Stack is empty!");
        }
        return stackMin.peek();
    }
}
