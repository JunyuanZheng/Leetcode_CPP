struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
/*
private:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        if (!root)
            return 0;
        int left = countNodes(root->left);
        if (k <= left)
            return kthSmallest(root->left, k);
        else if (left + 1 == k)
            return root->val;
        else
            return kthSmallest(root->right, k - left - 1);
    }
*/

private:
    void find(TreeNode *root, int &k, int &result) {
        if (!root)
            return;
        find(root->left, k, result);
        k -= 1;
        if (k == 0) {
            result = root->val;
            return;
        }
        find(root -> right, k, result);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        int result = 0;
        find(root, k, result);
        return result;
    }
};