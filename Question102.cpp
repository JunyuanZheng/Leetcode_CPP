#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> v;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            auto size = (int) q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i += 1) {
                TreeNode *t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
            v.push_back(tmp);
        }
        return v;
    }
};