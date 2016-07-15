public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if (array == null || array.length == 0) {
            return 0;
        }
        int currSum = 0;
        int greatestSum = Integer.MIN_VALUE;
        for (int i = 0; i < array.length; i++) {
            if (currSum <= 0) {
                currSum = array[i];		// 记录当前最大值
            } else {
                currSum += array[i];	// 当array[i]为正数时，加上之前的最大值并更新最大值。
            }

            if (currSum > greatestSum) {
                greatestSum = currSum;
            }
        }
        return greatestSum;
    }
}
