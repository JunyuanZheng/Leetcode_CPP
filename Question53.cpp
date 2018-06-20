#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        for (int i : nums) {
            sum = max(sum + i, i);
            result = max(sum, result);
        }
        return result;
    }
};