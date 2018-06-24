struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return head;

        RandomListNode * p = head;
        while (p != nullptr) {
            auto * temp = new RandomListNode(p -> label);
            temp -> next = p -> next;
            p -> next = temp;
            p = temp -> next;
        }

        p = head;
        while (p != nullptr && p -> next != nullptr) {
            if (p -> random != nullptr) {
                p -> next -> random = p -> random -> next;
            }
            p = p -> next -> next;
        }

        auto dummy1 = new RandomListNode(0);
        auto dummy2 = new RandomListNode(0);

        auto p1 = dummy1;
        auto p2 = dummy2;

        p1 -> next = head;
        p2 -> next = head;

        while (p1 -> next != nullptr) {
            p2 -> next = p1 -> next -> next;
            p1 -> next = p1 -> next;

            p1 = p1 -> next;
            p2 = p2 -> next;

            p1 -> next = p2 -> next;
            p2 -> next = nullptr;
        }

        return dummy2 -> next;
    }
};