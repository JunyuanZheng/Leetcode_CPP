#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        int head = preorder[preStart];
        auto node = new TreeNode(preorder[preStart]);
        int idx = (int) (find(inorder.begin() + inStart, inorder.begin() + inEnd, head) - inorder.begin());
        int left = idx - inStart;
        int right = inEnd - idx;
        node -> left = helper(preorder, inorder, preStart + 1, left + preStart, inStart, idx - 1);
        node -> right = helper(preorder, inorder, left + preStart + 1, preEnd, idx + 1, inEnd);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, (int) preorder.size() - 1, 0, (int) inorder.size() - 1);
    }
};