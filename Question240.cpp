#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int row = 0;
        int column = (int) matrix[row].size() - 1;

        while (row <= matrix.size() -1 && column >= 0) {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
                column -= 1;
            else
                row += 1;
        }
        return false;
    }
};