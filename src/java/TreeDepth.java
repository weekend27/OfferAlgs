/*
public class TreeNode {
	int val = 0;
	TreeNode left = null;
	TreeNode right = null;
	public TreeNode(int val) {
        this.val = val;
    }
};*/
public class Solution {
	public int TreeDepth(TreeNode pRoot)
    {
    	if (pRoot == null) return 0;

        int dLeft = TreeDepth(pRoot.left);
        int dRight = TreeDepth(pRoot.right);

        return (dLeft > dRight) ? (dLeft + 1) : (dRight + 1);
    }
}
