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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 != NULL && pRoot2 != NULL) {
            if (pRoot1->val == pRoot2->val) {
                result = equals(pRoot1, pRoot2);
            }
            if (!result) {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result) {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }

    bool equals(TreeNode* pRoot1, TreeNode* pRoot2) {

        // B子树递归到了尽头，说明之前比较的都相同，两者相等
        if (pRoot2 == NULL) {
            return true;
        }

        // A子树递归到了尽头，两者不等
        if (pRoot1 == NULL) {
            return false;
        }

        if (pRoot1->val != pRoot2->val) {
            return false;
        }

        return equals(pRoot1->left, pRoot2->left) && equals(pRoot1->right, pRoot2->right);
    }
};
