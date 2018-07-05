#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int size = (int) s.size(), result = 0;
        vector<int> v (128, -1);
        for (int i = 0, j = 0; i < size; i += 1) {
            char c = s[i];
            if (v[c] != -1)
                j = max(v[c] + 1, j);
            v[c] = i;
            result = max(result, i - j + 1);
        }
        return result;
    }
};