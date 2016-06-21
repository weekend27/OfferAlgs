/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        // 翻转单链表
        ListNode *prev, *curr, *next;
        prev = pHead;
        curr = pHead->next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        pHead->next = NULL;
        pHead = prev;

        return pHead;
    }
};
