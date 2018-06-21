#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool helper(vector<vector<char>>& board, string word, int idx, int row, int column) {
        if (idx >= word.size())
            return true;
        auto rSize = (int) board.size();
        auto cSize = (int) board[rSize - 1].size();
        if (row < 0 || row >= rSize || column < 0 || column >= cSize)
            return false;
        if (board[row][column] != word[idx])
            return false;
        board[row][column] ^= 128;
        bool exist = helper(board, word, idx + 1, row - 1, column) || helper(board, word, idx + 1, row + 1, column) || helper(board, word, idx + 1, row, column + 1) || helper(board, word, idx + 1, row, column - 1);
        board[row][column] ^= 128;
        return exist;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row += 1) {
            for (int column = 0; column < board[row].size(); column += 1) {
                if (helper(board, word, 0, row, column))
                    return true;
            }
        }
        return false;
    }
};