import java.util.Queue;
import java.util.LinkedList;
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
    // queue
    public TreeNode Convert(TreeNode pRootOfTree) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        TreeNode head = pRootOfTree;
        InOrderToQueue(head, queue);
        if (queue.isEmpty()) {
            return head;
        }
        head = queue.poll();
        TreeNode prev = head;
        prev.left = null;
        TreeNode curr = null;
        while (!queue.isEmpty()) {
            curr = queue.poll();
            prev.right = curr;
            curr.left = prev;
            prev = curr;
        }
        prev.right = null;
        return head;
    }

    private void InOrderToQueue(TreeNode head, Queue<TreeNode> queue) {
        if (head == null) return;

        InOrderToQueue(head.left, queue);
        queue.offer(head);
        InOrderToQueue(head.right, queue);
    }

    // recursive method
    public TreeNode Convert2(TreeNode pRootOfTree) {
        TreeNode head = pRootOfTree;
        if (head == null) {
            return null;
        }
        TreeNode last = process(head);
        head = last.right;
        last.right = null;
        return head;
    }

    private TreeNode process(TreeNode head) {
        if (head == null) {
            return null;
        }
        TreeNode leftE = process(head.left);	// left end
        TreeNode rightE = process(head.right);	// right end
        TreeNode leftS = leftE != null ? leftE.right : null;	// left start
        TreeNode rightS = rightE != null ? rightE.right : null;	// right start

        if (leftE != null && rightE != null) {
            leftE.right = head;
            head.left = leftE;
            head.right = rightS;
            rightS.left = head;
            rightE.right = leftS;
            return rightE;
        } else if (leftE != null) {
            leftE.right = head;
            head.left = leftE;
            head.right = leftS;
            return head;
        } else if (rightE != null) {
            head.right = rightS;
            rightS.left = head;
            rightE.right = head;
            return rightE;
        } else {
            head.right = head;
            return head;
        }
    }
}
