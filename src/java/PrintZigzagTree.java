import java.util.ArrayList;
import java.util.Stack;

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
public class Solution {
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        if (pRoot == null) {
            return result;
        }

        Stack<TreeNode> s1 = new Stack<>();		// store odd level nodes
        Stack<TreeNode> s2 = new Stack<>();		// store even level nodes

        s1.push(pRoot);
        TreeNode node;

        while (!s1.empty() || !s2.empty()) {
            ArrayList<Integer> list = new ArrayList<>();
            if (!s1.empty()) {
                while (!s1.empty()) {
                	node = s1.pop();
                	list.add(node.val);
                	if (node.left != null) {
                    	s2.push(node.left);
                	}
                	if (node.right != null) {
                    	s2.push(node.right);
                	}
            	}
                result.add(list);
            } else if (!s2.empty()) {
                while (!s2.empty()) {
                	node = s2.pop();
                	list.add(node.val);
                	if (node.right != null) {
                    	s1.push(node.right);
                	}
                	if (node.left != null) {
                    	s1.push(node.left);
                	}
            	}
                result.add(list);
            }
        }

        return result;
    }

}
