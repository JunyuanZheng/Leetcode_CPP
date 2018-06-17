#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int left = 0;
        int result = 0;
        vector<int> dict(256, -1);
        for (int i = 0; i < s.length(); i += 1) {
            char c = s[i];
            if (dict[c] != -1) {
                left = max(dict[c] + 1, left);
            }
            dict[c] = i;
            result = max(i - left + 1, result);
        }
        return result;
    }
};

int main()
{
    cout << Solution::lengthOfLongestSubstring("abcabcbb");
}