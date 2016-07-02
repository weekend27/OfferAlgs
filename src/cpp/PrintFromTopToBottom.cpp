/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        if (root == NULL) {
            return vector<int>();
        }

        vector<int> result;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* tmp = queue.front();
            queue.pop();
            result.push_back(tmp->val);
            if (tmp->left) {
                queue.push(tmp->left);
            }
            if (tmp->right) {
                queue.push(tmp->right);
            }
        }

        return result;

    }
};
