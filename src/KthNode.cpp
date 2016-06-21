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

    vector<TreeNode*> v;

    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == NULL || k < 1) {
            return NULL;
        }
        // 中序遍历
        inOrder(pRoot);
        if (k > v.size()) {
            return NULL;
        } else {
            return v[k-1];
        }
    }

    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        if (root->left) inOrder(root->left);
        v.push_back(root);
        if (root->right) inOrder(root->right);
    }

};
