#include <cstdlib>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int result = 0;
        int sign = dividend < 0 ^ divisor < 0;
        long long dvd = std::labs(dividend);
        long long dvs = std::labs(divisor);
        if (dvd == 0)
            return 0;
        while (dvd >= dvs) {
            long long tmp = dvs, multiple = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            result += multiple;
        }
        return sign == 0 ? result : -result;
    }
};