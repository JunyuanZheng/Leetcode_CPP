#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int l = 0, h = (int) s.size() - 1;
        while (l < h) {
            char tmp = s[l];
            s[l] = s[h];
            s[h] = tmp;
            l += 1;
            h -= 1;
        }
        return s;
    }
};