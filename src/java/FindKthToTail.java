/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        // corner case
        if (head == null || k == 0) {
            return null;
        }

        // p1 go k-1 steps first
        ListNode p1 = head;
        for (int i = 1; i < k; i++) {
            if (p1.next != null) {
                p1 = p1.next;
            } else {
                return null;
            }
        }

        // p2 from head, go with p1, the same speed
        ListNode p2 = head;
        while (p1.next != null) {
            p1 = p1.next;
            p2 = p2.next;
        }
        return p2;
    }
}
