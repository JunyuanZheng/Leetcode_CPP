#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> memo (nums.size(), 0);
        memo[0] = 1;
        int result = 1;
        for (int i = 1; i < (int) nums.size(); i += 1) {
            int tmp = 0;
            for (int j = 0; j < i; j += 1) {
                if (nums[i] > nums[j])
                    tmp = max(tmp, memo[j]);
            }
            memo[i] = tmp + 1;
            result = max(memo[i], result);
        }
        return result;
    }
};