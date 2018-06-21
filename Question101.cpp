struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool helper(TreeNode * r1, TreeNode * r2) {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        else if (r1 == nullptr || r2 == nullptr)
            return false;
        return r1 -> val == r2 -> val && helper(r1 -> right, r2 -> left) && helper(r1 -> left, r2 -> right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return helper(root -> left, root -> right);
    }
};