#include <vector>

using namespace std;

class Solution {
private:
    void swap(vector<vector<int>> & matrix, int r1, int c1, int r2, int c2) {
        int tmp = matrix[r1][c1];
        matrix[r1][c1] = matrix[r2][c2];
        matrix[r2][c2] = tmp;
    }
public:
    void rotate(vector<vector<int>> & matrix) {
        int size = (int) matrix.size();
        // swap diagonals
        for (int r = 0; r < size; r += 1) {
            for (int c = 0; c < r; c += 1) {
                swap(matrix, r, c, c, r);
            }
        }
        // swap columns
        for (int c = 0; c < size / 2; c += 1) {
            for (int r = 0; r < size; r += 1) {
                swap(matrix, r, c, r, size - 1 - c);
            }
        }
    }
};