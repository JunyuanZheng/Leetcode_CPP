#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i += 1) {
            vector<int> v ((unsigned long)i, 1);
            for (int j = 1; j < i - 1; j += 1) {
                v[j] = result[result.size() - 1][j - 1] + result[result.size() - 1][j];
            }
            result.push_back(v);
        }
        return result;
    }
};