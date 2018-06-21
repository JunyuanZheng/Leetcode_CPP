#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
/*
private:
    void helper(vector<int> & memo, TreeNode * root) {
        if (root == nullptr)
            return;
        if (root -> left != nullptr)
            helper(memo, root -> left);
        memo.push_back(root -> val);
        if (root -> right != nullptr)
            helper(memo, root -> right);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> memo;
        helper(memo, root);
        return memo;
    }
*/
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> memo;
        TreeNode *cur = root;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            memo.push_back(cur->val);
            cur = cur->right;
        }
        return memo;
    }
};