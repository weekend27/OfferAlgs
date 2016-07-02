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
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        int len1 = GetListLength(pHead1);
        int len2 = GetListLength(pHead2);

        int diff = abs(len1 - len2);

        ListNode *pLongHead, *pShortHead;
        if (len1 > len2) {
          pLongHead = pHead1;
          pShortHead = pHead2;
        } else {
          pLongHead = pHead2;
          pShortHead = pHead1;
        }

        while (diff > 0 && pLongHead != NULL) {
          pLongHead = pLongHead->next;
          diff--;
        }

        while (pLongHead != NULL && pShortHead != NULL && pLongHead != pShortHead) {
          pLongHead = pLongHead->next;
          pShortHead = pShortHead->next;
        }

        return pLongHead;
    }

    int GetListLength(ListNode *head) {
      if (head == NULL) {
        return 0;
      }
      ListNode *p = head;
      int len = 0;
      while (p != NULL) {
        p = p->next;
        len++;
      }
      return len;
    }
};
