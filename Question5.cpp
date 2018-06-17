#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int helper(string s, int left, int right) {
        int l = left;
        int r = right;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l -= 1;
            r += 1;
        }
        return r - l - 1;
    }

public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i += 1) {
            int l1 = helper(s, i, i);
            int l2 = helper(s, i - 1, i);
            int length = max(l1, l2);
            if (length >= end - start + 1) {
                start = i - length / 2;
                end = i + length / 2;
            }
        }
        return s.substr((unsigned long) start, (unsigned long) end - start + 1);
    }
};