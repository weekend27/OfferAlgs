/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        if (pHead1 == null || pHead2 == null) return null;

        ListNode p1 = pHead1;
        ListNode p2 = pHead2;
        int n = 0;
        while (p1.next != null) {
            p1 = p1.next;
            n++;
        }
        while (p2.next != null) {
            p2 = p2.next;
            n--;
        }

        if (p1 != p2) {
            return null;
        }

        p1 = n > 0 ? pHead1 : pHead2;	// longer list
        p2 = p1 == pHead1 ? pHead2 : pHead1;	// shorter list
        n = Math.abs(n);
        while (n != 0) {
            p1 = p1.next;
            n--;
        }
        while (p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }

        return p1;
    }
}
