struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto dummy = new ListNode(0);
        auto head = dummy;
        auto p1 = l1;
        auto p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p2->val < p1->val) {
                head->next = new ListNode(p2->val);
                p2 = p2->next;
            } else {
                head->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            head = head->next;
        }
        head->next = p1 ? p1 : p2;
        return dummy->next;
    }
};