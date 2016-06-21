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
    ListNode* deleteDuplication(ListNode* pHead)
    {
      if (pHead == NULL) {
        return NULL;
      }
      if (pHead->next == NULL) {
        return pHead;
      }

      ListNode* root = new ListNode(pHead->val-1);
      root->next = pHead;
      ListNode* prev = root;
      ListNode* curr = pHead;

      while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
          while (curr->next != NULL && curr->val == curr->next->val) {
            curr = curr->next;
          }
          prev->next = curr->next;
        }
        else {
          prev->next = curr;
          prev = prev->next;
        }
        curr = curr->next;
      }

      return root->next;

    }
};
