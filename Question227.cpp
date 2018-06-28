#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> memo;
        char sign = '+';
        int number = 0;
        for (int i = 0; i < s.size(); i += 1) {
            if (isnumber(s[i])) {
                number = number * 10 + s[i] - '0';
            }
            if (s[i] != ' ' && !isnumber(s[i]) || i == s.size() - 1) {
                if (sign == '+') {
                    memo.push(number);
                } else if (sign == '-') {
                    memo.push(-number);
                } else if (sign == '*') {
                    int value = memo.top();
                    memo.pop();
                    memo.push(value * number);
                } else if (sign == '/') {
                    int value = memo.top();
                    memo.pop();
                    memo.push(value / number);
                }
                sign = s[i];
                number = 0;
            }
        }

        int result = 0;
        while (!memo.empty()) {
            result += memo.top();
            memo.pop();
        }

        return result;
    }
};