/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetingNode = MeetingNode(pHead);
        if (meetingNode == NULL) {
            return NULL;
        }

        // get the number of nodes in the loop
        int nodesInLoop = 1;
        ListNode* currNode = meetingNode;
        while (currNode->next != meetingNode) {
            currNode = currNode->next;
            ++nodesInLoop;
        }

        // create two nodes: fast and slow
        ListNode* fast = pHead;
        ListNode* slow = pHead;

        // move fast first
        for (int i = 0; i < nodesInLoop; ++i) {
            fast = fast->next;
        }

        // move fast and slow together
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }


    // find the meeting node in the loop
    ListNode* MeetingNode(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return NULL;
        }

        ListNode* slow = pHead;
        ListNode* fast = pHead;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return fast;
            }
        }

        return NULL;
    }
};
