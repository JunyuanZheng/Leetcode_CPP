#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = (int) nums.size() - 1;
        int last = size;
        for (int i = size; i >= 0; i -= 1) {
            if (i + nums[i] >= last) {
                last = i;
            }
        }
        return last == 0;
    }
};