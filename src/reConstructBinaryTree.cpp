/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if (pre.size() == 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(pre[0]);

        vector<int> l_pre, r_pre, l_in, r_in;
        bool flag = true;

        // 找到中序遍历里与前序遍历第一个数相同的值，然后分成左右子树，随后递归确定进一步的左右子树
        for (int i = 0; i < pre.size(); ++i) {
            if (in[i] == pre[0]) {
                flag = false;
                continue;
            }

            if (flag == true) {
                l_pre.push_back(pre[i+1]);
                l_in.push_back(in[i]);
            } else {
                r_pre.push_back(pre[i]);
                r_in.push_back(in[i]);
            }
        }

        root->left = reConstructBinaryTree(l_pre, l_in);
        root->right = reConstructBinaryTree(r_pre, r_in);
        return root;
    }
};
