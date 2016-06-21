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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 递归版本
        ListNode *head;

        if (pHead1 == NULL && pHead2 == NULL) {
            return NULL;
        }
        else if (pHead1 == NULL) {
            return pHead2;
        }
        else if (pHead2 == NULL) {
            return pHead1;
        }
        else {
            if (pHead1->val < pHead2->val) {
                head = pHead1;
                head->next = Merge(pHead1->next, pHead2);
            } else {
                head = pHead2;
                head->next = Merge(pHead1, pHead2->next);
            }
            return head;
        }
    }
};
