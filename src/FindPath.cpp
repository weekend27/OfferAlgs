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



    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if (root == NULL) {
            return vector<vector<int> >();
        }

        int currSum = 0;
        vector<int> path;
        vector<vector<int> > result;

        FindPaths(root, expectNumber, path, result, currSum);

        return result;

    }

    void FindPaths(TreeNode* root, int expectNumber, vector<int> path, vector<vector<int> >& result, int currSum) {

        currSum += root->val;
        path.push_back(root->val);
        bool isLeaf = (root->left == NULL) && (root->right == NULL);

        if (currSum == expectNumber && isLeaf) {
            result.push_back(path);
        }

        if (root->left != NULL) {
            FindPaths(root->left, expectNumber, path, result, currSum);
        }

        if (root->right != NULL) {
            FindPaths(root->right, expectNumber, path, result, currSum);
        }

        path.pop_back();

    }

};
