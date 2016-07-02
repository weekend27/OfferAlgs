class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        if (pushV.size() == 0) {
            return false;
        }

        stack<int> stack;

        for (int i = 0, j = 0; i < pushV.size(); ) {
            stack.push(pushV[i++]);
            while (j < popV.size() && stack.top() == popV[j]) {
                stack.pop();
                j++;
            }
        }

        return stack.empty();

    }
};
