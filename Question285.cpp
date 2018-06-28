struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode * result = nullptr;
        while (root != nullptr) {
            if (root -> val > p -> val) {
                result = root;
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
        return result;
    }
};