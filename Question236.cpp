struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode * left = lowestCommonAncestor(root -> left, p, q);
        TreeNode * right = lowestCommonAncestor(root -> right, p, q);
        if (left && right)
            return root;
        else if ((root == p || root == q) && (left || right))
            return root;
        else if (left)
            return left;
        else if (right)
            return right;
        else
            return nullptr;
    }
};