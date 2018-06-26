#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long pre = (long) lower - 1;
        for (int i = 0; i <= nums.size(); i += 1) {
            long after = i == nums.size() ? (long) upper + 1 : (long) nums[i];
            if (after - pre == 2)
                result.push_back(to_string(pre + 1));
            else if (after - pre > 2)
                result.push_back(to_string(pre + 1) + "->" + to_string(after - 1));
            pre = after;
        }
        return result;
    }
};