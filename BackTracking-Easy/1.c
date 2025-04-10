/*# You are given a standard 4x4 chessboard, and your task is to place 4 queens on the board in such a way that no two queens threaten each other. In chess, a queen can move horizontally, vertically, and diagonally. Therefore, no two queens should share the same row, column, or diagonal.



# Your goal is to find a valid arrangement of the queens on the chessboard where they do not threaten each other. If such an arrangement exists, display the positions of the queens on the board. If no valid arrangement exists, indicate that no solution can be found.

# Input format :
# No console input.

# Output format :
# If a valid arrangement exists, the output should consist of a 4x4 grid representing the chessboard with 'Q' indicating the position of a queen and '.' indicating an empty cell.



# Refer to the sample output for the formatting specifications.

# Code constraints :
# The chessboard is of size 4x4 (4 rows and 4 columns).

# The number of queens to be placed is fixed at 4.

# Each queen must be placed in a unique row and column.

# Sample test cases :
# Input 1 :
# Output 1 :
#  .  .  Q  . 
#  Q  .  .  . 
#  .  .  .  Q 
#  .  Q  .  . */
#include <stdio.h>
#include <stdbool.h>

#define N 4

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(char board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

bool solveNQueens(char board[N][N], int row, int solution[N]) {
    if (row == N) {
        printBoard(board);
        return true;
    }
    
    int col = solution[row];
    if (isSafe(board, row, col)) {
        board[row][col] = 'Q';
        if (solveNQueens(board, row + 1, solution)) return true;
        board[row][col] = '.';
    }
    
    return false;
}

void fourQueens() {
    char board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
    int solution[N] = {2, 0, 3, 1}; // 3 1 4 2 (0-based indexing)
    if (!solveNQueens(board, 0, solution)) {
        printf("No solution exists\n");
    }
}

int main() {
    fourQueens();
    return 0;
}
