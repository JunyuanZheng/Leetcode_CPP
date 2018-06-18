struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto p1 = dummy;
        auto p2 = dummy;
        for (int i = 1; i <= n; i += 1) {
            p2 = p2->next;
        }
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return dummy->next;
    }
};