#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> memo;
        for (char c : s) {
            if (c == '{') {
                memo.push('}');
            } else if (c == '[') {
                memo.push(']');
            } else if (c == '(') {
                memo.push(')');
            } else if (memo.empty() || memo.top() != c) {
                return false;
            } else {
                memo.pop();
            }
        }
        return memo.empty();
    }
};