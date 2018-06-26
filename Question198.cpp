#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        for (int i : nums) {
            int tmp = cur;
            cur = max(pre + i, cur);
            pre = tmp;
        }
        return cur;
    }
};

int main() {
    vector<int> value { 2, 1, 1, 2 };
    Solution solution;
    solution.rob(value);
}