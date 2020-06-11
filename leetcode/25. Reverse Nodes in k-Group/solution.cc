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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        auto p = head;
        while (p && n < k) p = p->next, ++n;
        if (n < k) return head;
        p = head;
        ListNode *q = nullptr;
        while (n--) {
            auto r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        head->next = reverseKGroup(p, k);
        return q;
    }
};
