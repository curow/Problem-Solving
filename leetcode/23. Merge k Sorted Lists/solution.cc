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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (auto l : lists) {
            if (l) pq.push(l);
        }
        auto dummy = new ListNode(-1);
        auto p = dummy;
        while (!pq.empty()) {
            auto l = pq.top();
            pq.pop();
            p->next = l;
            p = p->next;
            l = l->next;
            if (l) pq.push(l);
        }
        return dummy->next;
    }
};
