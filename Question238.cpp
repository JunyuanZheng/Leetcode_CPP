#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int) nums.size();
        vector<int> result ((unsigned long) size, 1);
        for (int i = 1; i < size; i += 1) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = size - 1; i >=0; i += 1) {
            result[i] = result[i] * right;
            right = right * nums[i];
        }
        return result;
    }
};