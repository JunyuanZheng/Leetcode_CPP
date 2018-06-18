#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> memo;
        for (auto pointer = s.cbegin(); pointer != s.cend(); pointer += 1) {
            if (*pointer == ']' || *pointer == ')' || *pointer == '}') {
                if (memo.empty() || memo.top() != *pointer)
                    return false;
                memo.pop();
            } else {
                switch (*pointer) {
                    case '[':
                        memo.push(']');
                        break;
                    case '(':
                        memo.push(')');
                        break;
                    case '{':
                        memo.push('}');
                        break;
                }
            }
        }
        return memo.empty();
    }
};