import java.util.HashMap;

public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        HashMap<Integer, Integer> map = new HashMap<>();
        if (array == null || array.length == 0) return 0;

        for (int i = 0; i < array.length; i++) {
            Integer num = map.get(array[i]);
            if (num == null) {
                map.put(array[i], 1);
                num = 1;
            } else {
                map.put(array[i], ++num);
            }

            if (num > (array.length / 2)) {
                return array[i];
            }
        }

        return 0;
    }
}
