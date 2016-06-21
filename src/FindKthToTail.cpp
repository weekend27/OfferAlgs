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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 双指针方法，p1先走k步，然后两个指针再一起向前走，最后p2停留的位置元素就是所求

        if (pListHead == NULL || k == 0) {
            return NULL;
        }


        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;

        for (int i = 0; i < k - 1; i++) {
            if (p1->next != NULL) {
                p1 = p1->next;
            } else {
                return NULL;
            }
        }

        while (p1->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};
