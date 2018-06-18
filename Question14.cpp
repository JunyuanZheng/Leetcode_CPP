#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return ""s;
        string value = strs[0];
        int i = 1;
        while (i < strs.size()) {
            while (strs[i].find(value) != 0) {
                value.erase(value.length() - 1);
            }
            i += 1;
        }
        return value;
    }
};