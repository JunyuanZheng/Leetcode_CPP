#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    /*
    int numSquares(int n) {
        vector<int> memo ((unsigned long) n + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= n; i += 1) {
            int tmp = INT_MAX;
            for (int j = 1; i - j * j >= 0; j += 1) {
                tmp = min(tmp, memo[i - j * j] + 1);
            }
            memo[i] = tmp;
        }
        return memo[n];
    }
    */

    /*
    int numSquares(int n) {
        vector<int> memo {0};
        for (int i = 1; i <= n; i += 1) {
            int tmp = INT_MAX;
            for (int j = 1; i - j * j >= 0; j += 1) {
                tmp = min(tmp, memo[i - j * j] + 1);
            }
            memo.push_back(tmp);
        }
        return memo[n];
    }
    */

    int is_square(int n){
        int temp = (int) sqrt(n);
        return temp * temp == n;
    }
    int numSquares(int n) {
        while ((n & 3) == 0) //n%4 == 0
            n >>= 2;
        if ((n & 7) == 7) return 4; //n % 8 == 7
        if(is_square(n)) return 1;
        int sqrt_n = (int) sqrt(n);
        for(int i = 1; i<= sqrt_n; i++){
            if (is_square(n-i*i)) return 2;
        }
        return 3;
    }
};