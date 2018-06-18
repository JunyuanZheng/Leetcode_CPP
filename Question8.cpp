#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        bool sign = true;

        auto pointer = str.cbegin();

        while (*pointer == ' ')
            pointer += 1;

        if (*pointer == '-' || *pointer == '+') {
            sign = *pointer != '-';
            pointer += 1;
        }

        if (*pointer < '0' || *pointer > '9')
            return 0;

        while (pointer != str.cend()) {
            if (*pointer < '0' || *pointer > '9')
                break;
            result = result * 10 + *pointer - '0';
            if (result % 10 != *pointer - '0') {
                result = sign ? INT_MAX : INT_MIN;
                break;
            }
            pointer += 1;
        }

        return sign ? result : -result;
    }
};