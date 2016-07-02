public class Solution {
    public boolean Find(int [][] array,int target) {

        // corner case
        if (array == null || array.length < 1 || array[0].length < 1) {
            return false;
        }

        int rows = array.length;
        int cols = array[0].length;

        int i = 0;
        int j = cols - 1;

        while (i >= 0 && i < rows && j < cols && j >= 0) {
            if (array[i][j] == target) {
                return true;
            } else if (array[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
}
