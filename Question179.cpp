#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return stol(s1 + s2) > stol(s2 + s1);
        });
        string s;
        for (int n : nums)
            s += to_string(n);
        return s[0]=='0' ? "0" : s;
    }
};