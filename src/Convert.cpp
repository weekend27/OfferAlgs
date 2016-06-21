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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
      TreeNode* pLastNodeInList = NULL;
      ConvertNode(pRootOfTree, &pLastNodeInList);

      // return the head pointer
      TreeNode* pHeadOfList = pLastNodeInList;
      while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
        pHeadOfList = pHeadOfList->left;
      }

      return pHeadOfList;
    }

    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
      if (pNode == NULL) {
        return;
      }

      TreeNode* pCurrent = pNode;

      if (pCurrent->left != NULL) {
        ConvertNode(pCurrent->left, pLastNodeInList);
      }

      pCurrent->left = *pLastNodeInList;

      if (*pLastNodeInList != NULL) {
        (*pLastNodeInList)->right = pCurrent;
      }

      *pLastNodeInList = pCurrent;

      if (pCurrent->right != NULL) {
        ConvertNode(pCurrent->right, pLastNodeInList);
      }
    }

};
