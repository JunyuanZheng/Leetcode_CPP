#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool helper(TreeNode * root, long min, long max) {
        if (root == nullptr)
            return true;
        bool left = helper(root -> left, min, root -> val);
        bool right = helper(root -> right, root -> val, max);
        return root->val > min && root->val < max && left && right;
    }
public:
    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};