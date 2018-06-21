#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool top = false;
        bool left = false;
        if (matrix.empty())
            return;
        for (int r = 0; r < (int) matrix.size(); r += 1) {
            for (int c = 0; c < (int) matrix[r].size(); c += 1) {
                if (matrix[r][c] == 0) {
                    if (r == 0)
                        top = true;
                    if (c == 0)
                        left = true;
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for (int r = 1; r < (int) matrix.size(); r += 1) {
            for (int c = 1; c < (int) matrix[r].size(); c += 1) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0)
                    matrix[r][c] = 0;
            }
        }
        if (left) {
            for (int r = 0; r < (int) matrix.size(); r += 1) {
                matrix[r][0] = 0;
            }
        }
        if (top) {
            for (int c = 0; c < (int) matrix[0].size(); c += 1) {
                matrix[0][c] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> v {
            { 1, 0, 3 },
    };
    Solution solution;
    solution.setZeroes(v);
}