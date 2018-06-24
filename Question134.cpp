#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int tank = 0;
        int j = 0;
        for (int i = 0; i < (int) gas.size(); i += 1) {
            int delta = (gas[i] - cost[i]);
            sum += delta;
            tank += delta;
            if (tank < 0) {
                j = i + 1;
                tank = 0;
            }
        }
        return sum >= 0 ? j : -1;
    }
};