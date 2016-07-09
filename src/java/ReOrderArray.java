public class Solution {
    public void reOrderArray(int [] array) {
        // like insertion sort
        for (int i = 0; i < array.length; i++) {
            if (array[i] % 2 == 1) {
                for (int j = i; j > 0; j--) {
                    if (array[j - 1] % 2 == 0) {
                        int temp = array[j];
                        array[j] = array[j - 1];
                        array[j - 1] = temp;
                    }
                }
            }
        }
    }
}
