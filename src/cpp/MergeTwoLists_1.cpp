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
        if (pHead1->next == NULL && pHead2->next == NULL) {
            return NULL;
        }
        else if (pHead1->next == NULL) {
            return pHead2;
        }
        else if (pHead2->next == NULL) {
            return pHead1;
        }
        else {	// 合并
            ListNode *p1, *p2, *p3, *head;
            head = (ListNode*)malloc(sizeof(ListNode));
            head->next = NULL;  // 创建一个空链表
        	p1 = pHead1->next;	// 第一个节点
        	p2 = pHead2->next;	// 第一个节点
            p3 = head;			// 头结点（先于第一个节点）

            while (p1 != NULL && p2 != NULL) {
                if (p1->val < p2->val) {
                    p3->next = p1;
                    p1 = p1->next;
                } else {
                    p3->next = p2;
                    p2 = p2->next;
                }
                p3 = p3->next;
            }

            // pHead1没有遍历完
            while (p1 != NULL) {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }

            // pHead2没有遍历完
            while (p2 != NULL) {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }

            return head;

        }

    }
};
