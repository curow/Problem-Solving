/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head, *q = nullptr;
        int k = 2;
        while (k--) {
            auto r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        head->next = swapPairs(p);
        return q;
    }
};
