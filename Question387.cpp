#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v (26, 0);
        for (char c : s)
            v[c - 'a'] += 1;
        for (int i = 0; i < (int) s.size(); i += 1)
            if (v[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};