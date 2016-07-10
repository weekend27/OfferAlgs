/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/
public class Solution {
    public RandomListNode Clone(RandomListNode pHead)
    {
        if (pHead == null) {
            return null;
        }
        RandomListNode curr = pHead;
        RandomListNode next = null;

        // copy and link
        while (curr != null) {
            next = curr.next;
            curr.next = new RandomListNode(curr.label);
            curr.next.next = next;
            curr = next;
        }
        curr = pHead;
        RandomListNode currCopy = null;

        // set random pointer
        while (curr != null) {
            next = curr.next.next;
            currCopy = curr.next;
            currCopy.random = curr.random != null ? curr.random.next : null;
            curr = next;
        }
        RandomListNode res = pHead.next;
        curr = pHead;

        // split
        while (curr != null) {
            next = curr.next.next;
            currCopy = curr.next;
            curr.next = next;
            currCopy.next = next != null ? next.next : null;
            curr = next;
        }
        return res;
    }
}
