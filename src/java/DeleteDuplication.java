/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public ListNode deleteDuplication(ListNode pHead)
    {
        if (pHead == null) return null;

        if (pHead.next == null) return pHead;

        // fake head
        ListNode root = new ListNode(pHead.val - 1);
        root.next = pHead;

        ListNode prev = root;
        ListNode curr = pHead;

        while (curr != null && curr.next != null) {
            if (curr.val == curr.next.val) {
                while (curr.next != null && curr.val == curr.next.val) {
                    curr = curr.next;
                }
                prev.next = curr.next;
            } else {
                prev.next = curr;
                prev = prev.next;
            }
            curr = curr.next;
        }

        return root.next;
    }
}
