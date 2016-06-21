/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      vector<vector<int> > result;
      stack<TreeNode*> stack1, stack2;
      TreeNode* pNode;

      if (pRoot != NULL) {
        stack1.push(pRoot);
      }
      while (!stack1.empty() || !stack2.empty()) {
        vector<int> level;
        if (!stack1.empty()) {
          while (!stack1.empty()) {
            pNode = stack1.top();
            stack1.pop();
            if (pNode->left != NULL) {
              stack2.push(pNode->left);
            }
            if (pNode->right != NULL) {
              stack2.push(pNode->right);
            }
            level.push_back(pNode->val);
          }
          result.push_back(level);
        }
        else if (!stack2.empty()) {
          while (!stack2.empty()) {
            pNode = stack2.top();
            stack2.pop();
            if (pNode->right != NULL) {
              stack1.push(pNode->right);
            }
            if (pNode->left != NULL) {
              stack1.push(pNode->left);
            }
            level.push_back(pNode->val);
          }
          result.push_back(level);
        }
      }

      return result;

    }

};
