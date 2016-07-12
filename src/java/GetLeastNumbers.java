import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> result = new ArrayList<>();
        if (input == null || input.length == 0 || k <= 0 || k > input.length) {
            return result;
        }

        int low = 0;
        int high = input.length - 1;
        int index = partition(input, k, low, high);
        while (index != k - 1) {
            if (index > k - 1) {
                high = index - 1;
                index = partition(input, k, low, high);
            } else {
                low = index + 1;
                index = partition(input, k, low, high);
            }
        }

        for (int i = 0; i < k; i++) {
            result.add(input[i]);
        }

        return result;
    }

    private int partition(int[] array, int k, int low, int high) {
        int pivot = array[k - 1];
        swap(array, k - 1, low);
        while (low < high) {
            while (low < high && array[high] >= pivot) {
                high--;
            }
            swap(array, low, high);
            while (low < high && array[low] <= pivot) {
                low++;
            }
            swap(array, low, high);
        }
        return low;
    }

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
