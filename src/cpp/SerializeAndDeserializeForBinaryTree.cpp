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

    vector<int> buf;

    void dfs1(TreeNode* p) {
        if (!p) {
        	buf.push_back(0x23333);
        } else {
            buf.push_back(p->val);
            dfs1(p->left);
            dfs1(p->right);
        }
    }

    TreeNode* dfs2(int*& p) {
        if (*p == 0x23333) {
            ++p;
            return NULL;
        }
        TreeNode *res = new TreeNode(*p);
        ++p;
        res->left = dfs2(p);
        res->right = dfs2(p);
        return res;
    }

    char* Serialize(TreeNode *root) {
        buf.clear();
        dfs1(root);
        int *res = new int[buf.size()];
        for (unsigned int i = 0; i < buf.size(); ++i) {
            res[i] = buf[i];
        }
        return (char*)res;
    }

    TreeNode* Deserialize(char *str) {
    	int *p = (int*) str;
        return dfs2(p);
    }
};
