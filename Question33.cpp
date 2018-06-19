#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;
        int l = 0, h = (int) nums.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] <= nums[h]) {
                if (target > nums[mid] && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            } else {
                if (target >= nums[l] && target < nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};