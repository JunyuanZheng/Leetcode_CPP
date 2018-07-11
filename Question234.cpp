struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode * reverse(ListNode * head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode * tmp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return tmp;
    }
public:
    bool isPalindrome(ListNode *head) {
        ListNode * slow = head, * fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if (fast != nullptr)
            slow = slow -> next;

        slow = reverse(slow);
        fast = head;

        while (slow != nullptr) {
            if (slow->val != fast->val)
                return false;
            fast = fast -> next;
            slow = slow -> next;
        }

        return true;
    }
};