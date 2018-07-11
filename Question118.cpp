#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i += 1) {
            vector<int> tmp (static_cast<unsigned long>(i), 1);
            for (int j = 1; j <= i - 2; j += 1) {
                tmp[j] = result[i - 2][j - 1] + result[i - 2][j];
            }
            result.push_back(tmp);
        }
        return result;
    }
};