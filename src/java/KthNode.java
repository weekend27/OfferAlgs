/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
import java.util.Stack;

public class Solution {

    TreeNode KthNode(TreeNode pRoot, int k)
    {
        if (pRoot == null) {
            return null;
        }

        int count = 0;
        Stack<TreeNode> stack = new Stack<>();
        while (pRoot != null || !stack.empty()) {
            if (pRoot != null) {
                stack.push(pRoot);
                pRoot = pRoot.left;
            } else {
                pRoot = stack.pop();
                if (k == count + 1) {
                    return pRoot;
                } else {
                    count++;
                }
                pRoot = pRoot.right;
            }
        }

        return null;
    }

}
