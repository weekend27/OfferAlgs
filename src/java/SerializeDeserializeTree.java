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

    private int index = -1;

    String Serialize(TreeNode root) {
        StringBuffer sb = new StringBuffer();
        if (root == null) {
            sb.append("#,");
            return sb.toString();
        }
        sb.append(root.val + ",");
        sb.append(Serialize(root.left));
        sb.append(Serialize(root.right));
        return sb.toString();
  	}

    TreeNode Deserialize(String str) {
        index++;
        if (index >= str.length()) {
            return null;
        }

        String[] a = str.split(",");
        TreeNode node = null;
        if (!a[index].equals("#")) {
            node = new TreeNode(Integer.parseInt(a[index]));
            node.left = Deserialize(str);
            node.right = Deserialize(str);
        }

        return node;
  	}
}
