public class Solution {
    private boolean isBalanced = true;
    public boolean IsBalanced_Solution(TreeNode root) {
        getDepth(root);
        return isBalanced;
    }

    private int getDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = getDepth(root.left);
        int right = getDepth(root.right);

        if (Math.abs(left - right) > 1) {
            isBalanced = false;
        }

        return (left > right) ? (left + 1) : (right + 1);
    }
}
