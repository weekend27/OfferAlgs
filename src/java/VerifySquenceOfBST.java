import java.util.Arrays;

public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence == null || sequence.length == 0) return false;

        int root = sequence[sequence.length - 1];

        // left subtree node.val < root.val
        int i = 0;
        for (; i < sequence.length - 1; i++) {
            if (sequence[i] > root) {
                break;
            }
        }

        // right subtree node.val > root.val
        int j = i;
        for (; j < sequence.length - 1; j++) {
            if (sequence[j] < root) {
                return false;
            }
        }

        // check the left part
        boolean left = true;
        if (i > 0) {
            left = VerifySquenceOfBST(Arrays.copyOfRange(sequence, 0, i));
        }

        // check the right part
        boolean right = true;
        if (i < sequence.length - 1) {
            right = VerifySquenceOfBST(Arrays.copyOfRange(sequence, i, sequence.length - 1));
        }

        return left && right;
    }
}
