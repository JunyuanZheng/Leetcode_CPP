#include <vector>
#include <algorithm>

using namespace std;

class Solution {
/*
private:
    void reverse(vector<int> &nums, int start, int end) {
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
*/

public:
    void rotate(vector<int> &nums, int k) {
        k = k % (int) nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};