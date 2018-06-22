#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < (int) prices.size(); i += 1) {
            if (prices[i] > prices[i - 1])
                result += (prices[i] - prices[i - 1]);
        }
        return result;
    }
};