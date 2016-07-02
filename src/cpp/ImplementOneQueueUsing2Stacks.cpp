class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        // 只有在stack2为空的情况下，才能把stack1的元素进行迁移，不然会出错
        if (stack2.empty()) {
            while(!stack1.empty()){
            	stack2.push(stack1.top());
            	stack1.pop();
        	}
        }

        // 每次取stack2中顶端元素就能取得最早进入队列的值
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
