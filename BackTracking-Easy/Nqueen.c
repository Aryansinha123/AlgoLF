#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20 // Maximum board size (can be increased)

int board[MAX][MAX]; // Chessboard

// Function to print the board
void printSolution(int n) {
    static int solutionCount = 1;
    if (solutionCount>1)    
    {
        return;
    }
    printf("\nSolution %d:\n", solutionCount++);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) // Check left side
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper diagonal
        if (board[i][j]) return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--) // Check lower diagonal
        if (board[i][j]) return false;

    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(int col, int n) {
    if (col >= n) { // Base case: All queens are placed
        printSolution(n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) { // Try placing the queen in each row
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // Place queen
            res = solveNQueens(col + 1, n) || res; // Recur to place the rest
            board[i][col] = 0; // Backtrack
        }
    }
    return res;
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input! N must be between 1 and %d.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++) // Initialize board
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (!solveNQueens(0, n)) // Start solving from column 0
        printf("No solution exists for N = %d.\n", n);

    return 0;
}