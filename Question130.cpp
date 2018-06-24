#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>> & board, int row, int column, char search, char replace) {
        if (row < 0 || row >= (int) board.size() || column < 0 || column >=(int) board[row].size())
            return;
        if (board[row][column] == search) {
            board[row][column] = replace;
            dfs(board, row - 1, column, search, replace);
            dfs(board, row + 1, column, search, replace);
            dfs(board, row, column - 1, search, replace);
            dfs(board, row, column + 1, search, replace);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        auto row = (int) board.size();
        if (row < 1)
            return;
        auto column = (int) board[row - 1].size();

        for (int i = 0; i < row; i += 1) {
            dfs(board, i, 0, 'O', 'A');
            dfs(board, i, column - 1, 'O', 'A');
        }
        for (int i = 0; i < column; i += 1) {
            dfs(board, 0, i, 'O', 'A');
            dfs(board, row - 1, i, 'O', 'A');
        }


        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < column; c += 1) {
                dfs(board, r, c, 'O', 'X');
            }
        }

        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < column; c += 1) {
                dfs(board, r, c, 'A', 'O');
            }
        }
    }
};