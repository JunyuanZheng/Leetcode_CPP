struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* start = root;
        while (start != nullptr) {
            TreeLinkNode* cur = start;
            while (cur != nullptr) {
                if (cur -> left != nullptr)
                    cur -> left -> next = cur -> right;
                if (cur -> right != nullptr)
                    cur -> right -> next = cur -> next == nullptr ? nullptr : cur -> next -> left;
                cur = cur -> next;
            }
            start = start -> left;
        }
    }
};