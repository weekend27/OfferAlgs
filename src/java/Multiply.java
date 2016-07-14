import java.util.ArrayList;
public class Solution {
    public int[] multiply(int[] A) {
        int len = A.length;
        int[] before = new int[len];
        int[] after = new int[len];
        int[] B = new int[len];
        before[0] = 1;
        after[0] = 1;

        for (int i = 1; i < len; i++) {
            before[i] = before[i - 1] * A[i - 1];
            after[i] = after[i - 1] * A[len - i];
        }

        for (int i = 0; i < len; i++) {
            B[i] = before[i] * after[len - i - 1];
        }

        return B;
    }
}
