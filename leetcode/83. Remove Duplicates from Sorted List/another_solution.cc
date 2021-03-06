/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pa, *pb;
        pa = head;
        while (pa != nullptr) {
            pb = pa->next;
            if (pb == nullptr) break;
            if (pa->val == pb->val) {
                pa->next = pb->next;
            } else {
                pa = pb;
                pb = pb->next;
            }
        }
        return head;
    }
};

