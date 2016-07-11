public class Solution {
    public int FirstNotRepeatingChar(String str) {
        char[] c = str.toCharArray();
        int[] a = new int[256];
        for (char d : c) {
            a[(int) d]++;
        }

        for (int i = 0; i < c.length; i++) {
            if (a[(int) c[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
}
