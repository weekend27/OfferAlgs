public class Solution {
    public int JumpFloorII(int target) {
        if (target <= 1) return 1;
        return 2 * JumpFloorII(target - 1);
    }
}
