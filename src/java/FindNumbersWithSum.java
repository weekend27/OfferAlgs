import java.util.ArrayList;
public class Solution {
	public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        ArrayList<Integer> result = new ArrayList<>();

        if (array == null || array.length == 0) {
            return result;
        }

        int left = 0;
        int right = array.length - 1;

        while (left < right) {
            int temp = array[left] + array[right];
            if (temp == sum) {
                result.add(array[left]);
                result.add(array[right]);
                return result;
            } else if (temp > sum) {
                right--;
            } else {
                left++;
            }
        }

        return result;
    }
}
