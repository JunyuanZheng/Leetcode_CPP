#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = { false };
        bool columns[9][9] = { false };
        bool cells[9][9] = { false };
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int value = board[r][c] - '1';
                int k = r / 3 * 3 + c / 3;
                if (rows[r][value] || columns[c][value] || cells[k][value]) {
                    return false;
                }
                rows[r][value] = true;
                columns[c][value] = true;
                cells[k][value] = true;
            }
        }
        return true;
    }
};