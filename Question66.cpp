#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int overflow = 1;
        for (int i = (int) digits.size() - 1; i >= 0; i -= 1) {
            if (digits[i] + overflow <= 9) {
                digits[i] += overflow;
                return digits;
            } else {
                int tmp = digits[i];
                digits[i] = (digits[i] + overflow) % 10;
                overflow = (tmp + overflow) / 10;
            }
        }
        vector<int> result (digits.size() + 1, 0);
        result[0] = overflow;
        return result;
    }
};