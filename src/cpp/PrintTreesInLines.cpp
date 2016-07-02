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
          queue<TreeNode*> q1, q2;
          TreeNode* pNode;

          if (pRoot == NULL) {
            return result;
          }

          q1.push(pRoot);
          while (!q1.empty() || !q2.empty()) {
            vector<int> v1, v2;
            if (!q1.empty()){
              while (!q1.empty()) {
                pNode = q1.front();
                q1.pop();
                if (pNode->left != NULL) {
                  q2.push(pNode->left);
                }
                if (pNode->right != NULL) {
                  q2.push(pNode->right);
                }
                v1.push_back(pNode->val);
              }
              result.push_back(v1);
            }
            else if (!q2.empty()) {
              while (!q2.empty()) {
                pNode = q2.front();
                q2.pop();
                if (pNode->left != NULL) {
                  q1.push(pNode->left);
                }
                if (pNode->right != NULL) {
                  q1.push(pNode->right);
                }
                v2.push_back(pNode->val);
              }
              result.push_back(v2);
            }
          }

          return result;

        }
};
