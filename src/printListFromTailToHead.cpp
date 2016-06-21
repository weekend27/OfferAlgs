/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> result;
        ListNode* p = head;
        while (p) {
            // 不断地在vector的首部插入元素，达到逆序效果
            result.insert(result.begin(), p->val);
            p = p->next;
        }
        return result;
    }
};
