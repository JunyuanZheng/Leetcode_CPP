#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = (int) nums.size(), result = size;
        for (int i = 0; i < size; i += 1) {
            result ^= (i ^ nums[i]);
        }
        return result;
    }
};