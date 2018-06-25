#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo ((int) s.size() + 1, false);
        memo[0] = true;
        for (int i = 1; i <= s.size(); i += 1) {
            for (int j = 0; j < i; j += 1) {
                if (memo[j] && find(wordDict.begin(), wordDict.end(), s.substr((unsigned long) j, (unsigned long) (i - j))) != wordDict.end()) {
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[(int) s.size()];
    }
};