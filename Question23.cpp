#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class CompareListNode {
public:
    bool operator()(ListNode* const & n1, ListNode* const & n2) {
        return n1 -> val > n2 -> val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, CompareListNode> pq;
        for (ListNode* node : lists) {
            if (node != nullptr)
                pq.push(node);
        }
        ListNode * dummy = new ListNode(0);
        ListNode * head = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            head -> next = node;
            if (node -> next != nullptr)
                pq.push(node->next);
            head = head -> next;
            head -> next = nullptr;
        }
        return dummy -> next;
    }
};