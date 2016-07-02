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
    void Mirror(TreeNode *pRoot) {
        // 如果为空子树，直接返回
        if (pRoot == NULL) {
            return;
        }

        // 左右节点交换
        TreeNode *temp = NULL;
        temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        // 左右子树递归
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
