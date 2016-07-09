public class Solution {
    public int JumpFloor(int target) {
        if (target <= 1) {
            return 1;
        }

        int n1 = 1;
        int n2 = 1;
        int temp = 1;
        for (int i = 2; i <= target; i++) {
            temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
}
