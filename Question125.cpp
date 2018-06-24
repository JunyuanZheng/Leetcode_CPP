#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int l = 0, h = (int) s.size() - 1;
        while (l < h) {
            if (!isalnum(s[l]) || !isalnum(s[h])) {
                l += isalnum(s[l]) ? 0 : 1;
                h -= isalnum(s[h]) ? 0 : 1;
                continue;
            }
            if (tolower(s[l]) == tolower(s[h])) {
                l += 1;
                h -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};