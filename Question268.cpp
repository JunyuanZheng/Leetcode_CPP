#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = (int) nums.size();
        for (int i = 0; i < nums.size(); i += 1) {
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};