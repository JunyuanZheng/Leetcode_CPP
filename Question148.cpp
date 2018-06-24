struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode *merge(ListNode *h1, ListNode *h2) {
        auto dummy = new ListNode(0);
        auto head = dummy;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val > h2->val) {
                head->next = h2;
                h2 = h2->next;
            } else {
                head->next = h1;
                h1 = h1->next;
            }
            head = head->next;
        }
        head->next = h1 == nullptr ? h2 : h1;
        return dummy->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *headb = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(headb));
    }
};