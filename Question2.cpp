struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        ListNode* dummy(nullptr);
        ListNode* head = dummy;
        while (l1 || l2 || overflow) {
                int sum = l1 ? l1->val : 0 + l2 ? l2->val : 0;
                head->next = new ListNode(sum % 10);
                head = head->next;
                overflow = sum / 10;
        }
        return dummy->next;
    }
};
