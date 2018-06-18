#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int num : nums) {
            if (idx == 0 || num > nums[idx - 1]) {
                nums[idx++] = num;
            }
        }
        return idx;
    }
};