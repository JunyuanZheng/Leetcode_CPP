#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size() - 1) / 2];
    }
    */
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for (int i : nums) {
            if (count == 0)
                candidate = i;
            count += i == candidate ? 1 : -1;
        }
        return candidate;
    }
};