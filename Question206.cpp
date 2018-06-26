struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /*
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        ListNode * value = reverseList(head -> next);

        head -> next -> next = head;
        head -> next = nullptr;

        return value;
    }
    */

    /*
    ListNode *reverseList(ListNode *head) {
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while (cur != nullptr) {
            ListNode * tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    */

    ListNode *reverseList(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = head;
        while (cur && cur -> next) {
            ListNode* temp = dummy -> next;
            dummy -> next = cur -> next;
            cur -> next = cur -> next -> next;
            dummy -> next -> next = temp;
        }
        return dummy -> next;
    }
};