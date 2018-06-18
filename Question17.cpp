#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> v {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(vector<string> & result, const string & digits, string & s, int idx) {
        if (idx >= digits.length()) {
            if (s.length() != 0) {
                const string & tmp {s};
                result.push_back(tmp);
            }
            return;
        }
        int value = digits[idx] - '0';
        for (int i = 0; i < v[value].length(); i += 1) {
            s += v[value][i];
            helper(result, digits, s, idx + 1);
            s.erase(s.length() - 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string s;
        helper(result, digits, s, 0);
        return result;
    }
};