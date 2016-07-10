/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    // 递归解法
    public void Mirror(TreeNode root) {
        if (root == null) return;

        if (root.left == null && root.right == null) return;

        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        Mirror(root.left);
        Mirror(root.right);
    }
    // 非递归解法
    public void Mirror2(TreeNode root) {
        if (root == null) return;

        if (root.left == null && root.right == null) return;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.empty()) {
            TreeNode top = stack.pop();

            // swap
            if (top.left != null || top.right != null) {
                TreeNode temp = top.left;
                top.left = top.right;
                top.right = temp;
            }

            if (top.left != null) {
                stack.push(top.left);
            }

            if (top.right != null) {
                stack.push(top.right);
            }
        }
    }
}
