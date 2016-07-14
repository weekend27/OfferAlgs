import java.util.List;
import java.util.ArrayList;

public class Solution {
    private Heap maxHeap = new Heap(Heap.isMaxHeap);
    private Heap minHeap = new Heap(Heap.isMinHeap);

    public void Insert(Integer num) {
        // total size is even, insert num into maxHeap
    	if (((maxHeap.size() + minHeap.size()) & 1) == 0) {
            if (minHeap.size() > 0 && num > minHeap.peek()) {
                minHeap.add(num);
                maxHeap.add(minHeap.pop());
            } else {
                maxHeap.add(num);
            }
        }
        // total size is odd, insert num into minHeap
        else {
            if (maxHeap.size() > 0 && num < maxHeap.peek()) {
                maxHeap.add(num);
                minHeap.add(maxHeap.pop());
            } else {
                minHeap.add(num);
            }
        }
    }

    public Double GetMedian() {
        double res = 0.0;
        if (((maxHeap.size() + minHeap.size()) & 1) == 0) {
            res = (maxHeap.peek() + minHeap.peek()) / 2.0;
        } else {
            res = maxHeap.peek();
        }
        return res;
    }

}

// Heap class, including maxHeap and minHeap
class Heap {
    public List<Integer> list = null;
    public static final boolean isMaxHeap = true;
    public static final boolean isMinHeap = false;
    private boolean flag = true;	// true is MaxHeap, false is MinHeap

    public Heap() {
        this.list = new ArrayList<Integer>();
    }

    public Heap(boolean flag) {
        this.list = new ArrayList<Integer>();
        this.flag = flag;
    }

    // get heap size
    public int size() {
        return this.list.size();
    }

    // get heap top element
    public int peek() {
        if (list.size() == 0) return 0;
        return list.get(0);
    }

    // insert element, adjust heap from bottom to top
    public void add(int val) {
        this.list.add(val);
        int i = list.size() - 1;
        int index;
        int parent;
        int curr;
        while (i > 0) {
            index = (i - 1) / 2;
            parent = list.get(index);
            curr = list.get(i);
            if (flag == true && parent < curr) {
                swap(index, i);
            } else if (flag == false && parent > curr) {
                swap(index, i);
            }
            i = index;
        }
    }

    /**
     * pop the top element out, and adjust heap
     * 1> pop the top element
     * 2> put the last element to the top pos
     * 3> adjust heap from top to bottom
     */
    public int pop() {
        if (list.size() == 0) return -1;
        int res = list.get(0);
        list.set(0, list.get(list.size() - 1));
        list.remove(list.size() - 1);
        int len = list.size();
        int i = 0;
        int left, right;
        while (i < len) {
            left = (i << 1) + 1;
            right = (i << 1) + 2;
            int index = i;
            if (flag == true) {
                if (left < len && list.get(left) > list.get(index)) index = left;
                if (right < len && list.get(right) > list.get(index)) index = right;
            } else {
                if (left < len && list.get(left) < list.get(index)) index = left;
                if (right < len && list.get(right) < list.get(index)) index = right;
            }
            if (index != i) {
                swap(index, i);
                i = index;
            } else {
                break;
            }
        }
        return res;
    }

    // swap two elements in list
    public void swap(int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }

}
