#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size())
            return;
        if (grid[r][c] == '0' || grid[r][c] == 'X')
            return;
        grid[r][c] = 'X';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for (int row = 0; row < (int) grid.size(); row += 1) {
            for (int column = 0; column < (int) grid[row].size(); column += 1) {
                if (grid[row][column] == '1') {
                    counter += 1;
                    dfs(grid, row, column);
                }
            }
        }
        return counter;
    }
};