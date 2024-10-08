#include <bits/stdc++.h>
using namespace std;

// Function to print the solution (all possible board configurations)
void print(vector<vector<string>> &ans) {
    for (auto &row : ans) {
        for (auto elem : row) {
            cout << elem << endl; // Print each row of the board
        }
        cout << endl; // Blank line between different solutions
    }
}

// Function to check if placing a queen at board[row][col] is safe
bool issafe(int row, int col, vector<string> &board, int n) {
    int dcol = col; // Save the original column for restoration
    int drow = row; // Save the original row for restoration

    // Check upper diagonal (row-1, col-1), moving diagonally left upwards
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false; // Queen found, not safe
        row--;
        col--;
    }

    // Restore row and column
    col = dcol;
    row = drow;

    // Check the left side (row, col-1), moving left on the same row
    while (col >= 0) {
        if (board[row][col] == 'Q') return false; // Queen found, not safe
        col--;
    }
    // Restore row and column
    col = dcol;
    row = drow;
    // Check lower diagonal (row+1, col-1), moving diagonally left downwards
    while (col >= 0 && row < n) {
        if (board[row][col] == 'Q') return false; // Queen found, not safe
        col--;
        row++;
    }
    // If no queens are found in these directions, the position is safe
    return true;
}

// Function to recursively solve the N-Queens problem
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    // Base case: All queens are placed
    if (col == n) {
        ans.push_back(board); // Store the current board configuration
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        // If it's safe to place a queen at board[row][col]
        if (issafe(row, col, board, n)) {
            board[row][col] = 'Q'; // Place the queen
            solve(col + 1, board, ans, n); // Recursively place queens in the next column
            board[row][col] = '.'; // Backtrack and remove the queen
        }
    }
}

int main() {
    int n = 4; // You can change this to any size, e.g., 8 for the classic 8-Queens problem
    vector<string> board(n, string(n, '.')); // Initialize the board with '.' to represent empty spaces
    vector<vector<string>> ans; // To store all the solutions

    solve(0, board, ans, n); // Start solving from the 0th column
    print(ans); // Print all possible solutions

    return 0;
}
