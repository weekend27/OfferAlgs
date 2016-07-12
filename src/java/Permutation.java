import java.util.ArrayList;
import java.util.HashSet;
import java.util.Collections;

public class Solution {
    public ArrayList<String> Permutation(String str) {
        ArrayList<String> res = new ArrayList<>();
        if (str == null || str.length() == 0) {
            return res;
        }

        // use set to skip duplicates
        HashSet<String> set = new HashSet<>();
        char[] strArray = str.toCharArray();
        func(strArray, set, 0);

        // add all elements in set to arraylist
        res.addAll(set);
        // sort
        Collections.sort(res);
        return res;
    }

    private void func(char[] str, HashSet<String> set, int k) {
        if (k == str.length) {
            set.add(new String(str));
            return;
        }

        for (int i = k; i < str.length; i++) {
            swap(str, i, k);
            func(str, set, k + 1);
            swap(str, i, k);
        }
    }

    private void swap(char[] str, int i, int j) {
        if (i != j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}
