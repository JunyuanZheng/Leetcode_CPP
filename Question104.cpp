#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root -> right), maxDepth(root -> left));
    }
};