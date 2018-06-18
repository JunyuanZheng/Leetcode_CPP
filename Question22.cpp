#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void helper(vector<string> & result, string s, int left, int right) {
        if (left > right)
            return;
        if (left == 0 && right == 0) {
            string tmp (s);
            result.emplace_back(tmp);
            return;
        }
        if (left > 0) {
            string tmp = s + '(';
            helper(result, tmp, left - 1, right);
        }
        if (right > 0) {
            string tmp = s + ')';
            helper(result, tmp, left, right - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(result, "", n, n);
        return result;
    }
};