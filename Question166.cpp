#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string sb;
        sb += numerator < 0 ^ denominator < 0 ? "-" : "";

        long lnumerator = labs(numerator);
        long ldenominator = labs(denominator);
        sb += to_string(lnumerator / ldenominator);

        if (lnumerator % ldenominator == 0)
            return sb;
        else
            sb += ".";

        long lreminder = lnumerator % ldenominator;
        unordered_map<long, long> map;
        while (lreminder != 0) {
            if (map[lreminder]) {
                sb.insert((unsigned long)map[lreminder], "(");
                sb += ")";
                break;
            }
            map[lreminder] = sb.size();
            lreminder *= 10;
            sb += to_string(lreminder / ldenominator);
            lreminder %= ldenominator;
        }

        return sb;
    }
};