#include <cstdlib>

using namespace std;

class Solution {
private:
    double helper(double x, long n) {
        if (n == 0)
            return 1;
        double mid = helper(x, n / 2);
        if (n % 2 == 0)
            return mid * mid;
        else
            return mid * mid * x;
    }
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return helper(x, n);
    }
};