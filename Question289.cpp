#include <vector>

using namespace std;

class Solution {
private:
    int isAlive(vector<vector<int>>& board, int row, int column) {
        if (row < 0 || row >= board.size() || column < 0 || column >= board[row].size())
            return 0;
        return (board[row][column] & 1) == 1 ? 1 : 0;
    }

    int counter(vector<vector<int>>& board, int row, int column) {
        int result = 0;
        result += isAlive(board, row - 1, column - 1);
        result += isAlive(board, row - 1, column);
        result += isAlive(board, row - 1, column + 1);
        result += isAlive(board, row, column - 1);
        result += isAlive(board, row, column + 1);
        result += isAlive(board, row + 1, column - 1);
        result += isAlive(board, row + 1, column);
        result += isAlive(board, row + 1, column + 1);
        return result;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int r = 0; r < board.size(); r += 1) {
            for (int c = 0; c < board[r].size(); c += 1) {
                int value = counter(board, r, c);
                cout << value << endl;
                if (((board[r][c] & 1) == 1 && value >= 2 && value <= 3) ||  ((board[r][c] & 1) == 0 && value == 3))
                    board[r][c] = (board[r][c] | 2);
            }
        }
        for (int r = 0; r < board.size(); r += 1) {
            for (int c = 0; c < board[r].size(); c += 1) {
                board[r][c] >>= 1;
            }
        }
    }
};

int main() {
    vector<vector<int>> v {
            {0,1,0},
            {0,0,1},
            {1,1,1},
            {0,0,0}
    };
    Solution solution;
    solution.gameOfLife(v);
}