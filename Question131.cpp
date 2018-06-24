#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        int l = 0, h = (int) s.size() - 1;
        while (l < h) {
            if (s[l] != s[h])
                return false;
            l += 1;
            h -= 1;
        }
        return true;
    }
    void subPartition(const string & s, unsigned long idx, vector<vector<string>> & result, vector<string> & memo) {
        if (idx >= s.size()) {
          result.push_back(memo);
          return;
        }
        for (unsigned long i = idx + 1; i <= s.size(); i += 1) {
            string sub (s.begin() + idx, s.begin() + i);
            if (isPalindrome(sub)) {
                memo.push_back(sub);
                subPartition(s, i, result, memo);
                memo.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> memo;
        subPartition(s, 0, result, memo);
        return result;
    }
};