#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec ((unsigned long) n + 1, false);
        int result = 0;
        for (int i = 2; i < n; i += 1) {
            if (!vec[i]) {
                result += 1;
                for (int j = 2; i * j < n; j += 1) {
                    vec[i * j] = true;
                }
            }
        }
        return result;
    }
};