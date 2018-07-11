#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool sign = true;
        int result = 0;
        int idx = 0;

        while (idx < (int) str.length() && str[idx] == ' ')
            idx += 1;

        if (str[idx] == '-' || str[idx] == '+') {
            sign = str[idx] != '-';
            idx += 1;
        }

        if (str[idx] < '0' || str[idx] > '9')
            return 0;

        while (idx < (int) str.length() && str[idx] >= '0' && str[idx] <= '9') {
            result = result * 10 + (str[idx] - '0');
            if (result % 10 != (str[idx] - '0') % 10) {
                result = sign ? INT_MAX : INT_MIN;
                break;
            }
            idx += 1;
        }

        return sign ? result : -result;
    }
};