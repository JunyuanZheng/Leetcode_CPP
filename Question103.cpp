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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode *> s;
        if (root != nullptr)
            s.push(root);
        int counter = 1;
        while (!s.empty()) {
            vector<int> local;
            stack<TreeNode *> temp;
            while (!s.empty()) {
                TreeNode * node = s.top();
                s.pop();
                local.push_back(node -> val);
                if (counter % 2 == 0) {
                    if (node -> left != nullptr)
                        temp.push(node -> left);
                    if (node -> right != nullptr)
                        temp.push(node -> right);
                } else {
                    if (node -> right != nullptr)
                        temp.push(node -> right);
                    if (node -> left != nullptr)
                        temp.push(node -> left);
                }
            }
            result.push_back(local);
            s = temp;
            counter += 1;
        }
        return result;
    }
};