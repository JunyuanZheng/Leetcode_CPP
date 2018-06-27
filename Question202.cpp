#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (set.find(n) == set.end()) {
            set.insert(n);
            int tmp = 0;
            while (n > 0) {
                tmp += ((n % 10) * (n % 10));
                n = n / 10;
            }
            n = tmp;
        }
        return n == 1;
    }
};