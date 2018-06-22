#include <vector>

using namespace std;

class Solution {
private:
    void helper(vector<int> & nums, int l, int r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int l = 0, r = (int) nums.size() -1, idx = 0;
        while (idx <= r) {
            if (nums[idx] == 0) {
                helper(nums, l++, idx++);
            } else if (nums[idx] == 1) {
                idx++;
            } else {
                helper(nums, r--, idx);
            }
        }
    }
};