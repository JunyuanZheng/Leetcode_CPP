#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> memo((unsigned long) amount + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= amount; i += 1) {
            int tmp = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && memo[i - coin] != INT_MAX)
                    tmp = min(tmp, memo[i - coin] + 1);
            }
            memo[i] = tmp;
        }
        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};