#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int helper(vector<int> & memo, string & s, int idx) {
        if (memo[idx] != -1)
            return memo[idx];
        if (s[idx] == '0')
            return 0;
        int sum = 0;
        int value = 0;
        for (int i = idx; i < s.size(); i += 1) {
            int c = s[i] - '0';
            value = value * 10 + c;
            if (value > 26)
                break;
            sum += helper(memo, s, i + 1);
        }
        memo[idx] = sum;
        return sum;
    }
public:
    int numDecodings(string s) {
        vector<int> memo (s.size() + 1, -1);
        memo[s.size()] = 1;
        memo[s.size()-1] = s[s.size() - 1] != '0' ? 1 : 0;
        return helper(memo, s, 0);
    }
};