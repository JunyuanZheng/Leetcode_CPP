struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;
        ListNode * odd = head, * evenhead = head -> next, * even = evenhead;
        while (even != nullptr && even -> next != nullptr) {
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;
    }
};
