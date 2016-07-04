public class Solution {
    public int movingCount(int threshold, int rows, int cols)
    {
        int[][] flag = new int[rows][cols];
        return helper(flag, 0, 0, rows, cols, threshold);
    }

    private int helper(int[][] flag, int i, int j, int rows, int cols, int threshold) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || flag[i][j] == 1 || numSum(i) + numSum(j) > threshold) return 0;
        flag[i][j] = 1;
        return helper(flag, i - 1, j, rows, cols, threshold)
            +  helper(flag, i, j - 1, rows, cols, threshold)
            +  helper(flag, i + 1, j, rows, cols, threshold)
            +  helper(flag, i, j + 1, rows, cols, threshold)
            +  1;
    }

    private int numSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
