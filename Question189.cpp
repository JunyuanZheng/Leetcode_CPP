#include <vector>

using namespace std;

class Solution {
private:
    void reverse(vector<int> & nums, int start, int end) {
        if (start < 0 || end > (int) nums.size() - 1)
            return;
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start += 1;
            end -= 1;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % (int) nums.size();
        reverse(nums, 0, (int) nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, (int) nums.size() - 1);
    }
};