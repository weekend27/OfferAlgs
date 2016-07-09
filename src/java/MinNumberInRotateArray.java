import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {

        // corner case
        if (array.length == 0) return 0;

    	int left = 0;
        int right = array.length - 1;
        int mid = 0;

        while (array[left] >= array[right]) {
            if (right - left == 1) {
                mid = right;
                break;
            }

            mid = left + (right - left) / 2;

            if (array[left] == array[mid] && array[right] == array[mid]) {
                return findMin(array, left, right);
            }

            if (array[mid] >= array[left]) {
                left = mid;
            } else if (array[mid] <= array[right]) {
                right = mid;
            }
        }

        return array[mid];

    }

    public int findMin(int[] array, int left, int right) {
        int result = array[left];
        for (int i = left + 1; i <= right; i++) {
            if (array[i] < result) {
                result = array[i];
            }
        }
        return result;
    }
}
