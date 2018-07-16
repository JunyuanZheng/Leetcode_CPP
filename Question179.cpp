#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int value1, int value2) {
            string s1 = to_string(value1);
            string s2 = to_string(value2);
            return stol(s1 + s2) > stol(s2 + s1);
        });
        if (nums[0] == 0)
            return to_string(0);
        string s;
        for (int i : nums)
            s += to_string(i);
        return s;
    }
};