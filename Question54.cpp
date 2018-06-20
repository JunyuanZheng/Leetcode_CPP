#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
        int top = 0, bottom = (int) matrix.size() - 1, left = 0, right = (int) matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; top <= bottom && i <= right; i += 1) {
                result.push_back(matrix[top][i]);
            }
            top += 1;
            for (int i = top; left <= right && i <= bottom; i += 1) {
                result.push_back(matrix[i][right]);
            }
            right -= 1;
            for (int i = right; bottom >= top && i >= left; i -= 1) {
                result.push_back(matrix[bottom][i]);
            }
            bottom -= 1;
            for (int i = bottom; left <= right && i >= top; i -= 1) {
                result.push_back(matrix[i][left]);
            }
            left += 1;
        }
        return result;
    }
};