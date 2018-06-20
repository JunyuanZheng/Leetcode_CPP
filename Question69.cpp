#include <climits>

class Solution {
public:
    int mySqrt(int x) {
        long low = 0;
        long high = x;
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid * mid == x)
                return (int) mid;
            if (mid * mid < x) {
                if ((mid  + 1) * (mid + 1) > x)
                    return (int) mid;
                else
                    low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) low;
    }
};