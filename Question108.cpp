#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        auto * t = new TreeNode(nums[mid]);
        t -> left = helper(nums, l, mid - 1);
        t -> right = helper(nums, mid + 1, r);
        return t;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int) nums.size() - 1);
    }
};