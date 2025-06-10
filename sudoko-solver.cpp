#include <bits/stdc++.h>
using namespace std;

class SudokuSolver {
    int n, boxSize;
    vector<vector<int>> board;

    bool isSafe(int row, int col, int num) {
        for (int x = 0; x < n; x++) {
            if (board[row][x] == num || board[x][col] == num)
                return false;
        }
        int startRow = row - row % boxSize;
        int startCol = col - col % boxSize;
        for (int i = 0; i < boxSize; i++) {
            for (int j = 0; j < boxSize; j++) {
                if (board[startRow + i][startCol + j] == num)
                    return false;
            }
        }
        return true;
    }

    bool solve() {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 0) {
                    for (int num = 1; num <= n; num++) {
                        if (isSafe(row, col, num)) {
                            board[row][col] = num;
                            if (solve()) return true;
                            board[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    SudokuSolver(int size, vector<vector<int>> inputBoard) {
        n = size;
        boxSize = sqrt(n);
        board = inputBoard;
    }

    void solveAndPrint() {
        if (solve()) {
            for (auto& row : board) {
                for (int num : row)
                    cout << num << " ";
                cout << "\n";
            }
        } else {
            cout << "No solution exists!" << endl;
        }
    }
};

int main() {
    int n = 9;
    vector<vector<int>> board = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };

    SudokuSolver solver(n, board);
    solver.solveAndPrint();
    return 0;
}