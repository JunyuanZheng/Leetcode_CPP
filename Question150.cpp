#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    int toNumber(string s) {
        int result = 0;
        bool sign = true;
        for (auto i = s.cbegin(); i != s.cend(); i += 1) {
            if (*i == '+' || *i == '-') {
                sign = *i == '+';
            } else {
                result = result * 10 + (*i - '0');
            }
        }
        return sign ? result : -result;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for (const string &token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                temp.push(toNumber(token));
            } else {
                int v1 = temp.top();
                temp.pop();
                int v2 = temp.top();
                temp.pop();
                if (token == "+")
                    temp.push(v1 + v2);
                else if (token == "-")
                    temp.push(v2 - v1);
                else if (token == "*")
                    temp.push(v2 * v1);
                else if (token == "/")
                    temp.push(v2 / v1);
            }
        }
        return temp.top();
    }
};