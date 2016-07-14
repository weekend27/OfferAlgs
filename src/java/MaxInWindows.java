import java.util.ArrayList;
import java.util.ArrayDeque;

public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer> res = new ArrayList<>();
        if (num == null || size < 1 || size > num.length) {
            return res;
        }

        int begin;
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < num.length; i++) {
            // the beginnig index in queue
            begin = i - size + 1;

            // insert i into empty queue
            if (queue.isEmpty()) {
                queue.add(i);
            }
            // delete the head of queue if queue.size > size
            else if (begin > queue.peekFirst()) {
                queue.pollFirst();
            }

            // delete old nums that less than num[i]
            while ((!queue.isEmpty()) && num[queue.peekLast()] <= num[i]) {
                queue.pollLast();
            }

            // add index to queue
            queue.add(i);

            // add num to result list
            if (begin >= 0) {
                res.add(num[queue.peekFirst()]);
            }
        }

        return res;
    }
}
