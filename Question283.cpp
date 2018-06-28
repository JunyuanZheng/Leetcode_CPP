#include <vector>

using namespace std;

class Solution {
public:
    /*
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] != 0)
                nums[idx++] = nums[i];
        }
        for (int i = idx; i < nums.size(); i += 1) {
            nums[i] = 0;
        }
    }
    */
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] != 0)
                swap(nums[idx++], nums[i]);
        }
    }
};