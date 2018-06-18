#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < (int) nums.size() - 2; i += 1) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int low = i + 1, high = (int) nums.size() - 1, sum = 0 - nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        vector<int> tmp{nums[low], nums[i], nums[high]};
                        result.push_back(tmp);
                        while (low < high && nums[low] == nums[low + 1])
                            low += 1;
                        while (high > low && nums[high - 1] == nums[high])
                            high -= 1;
                        low += 1;
                        high -= 1;
                    } else if (nums[low] + nums[high] < sum) {
                        low += 1;
                    } else {
                        high -= 1;
                    }
                }
            }
        }
        return result;
    }
};