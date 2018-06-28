struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode * reverse(ListNode * head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        ListNode * tmp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return tmp;
    }
public:
    bool isPalindrome(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        if (fast != nullptr)
            slow = slow -> next;

        slow = reverse(slow);
        fast = head;

        while (fast != nullptr && slow != nullptr) {
            if (fast -> val != slow -> val)
                return false;
            fast = fast -> next;
            slow = slow -> next;
        }

        return true;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(2);
    ListNode* l4 = new ListNode(1);

    l1 -> next = l2;
    l2 -> next = l3;
    l3 -> next = l4;

    Solution solution;
    solution.isPalindrome(l1);
}