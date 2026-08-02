// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Function prototypes
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p);

int main() {
    int choice;

    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        // ---------------- PART A: TRANSPOSE ----------------
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
            cout << "Error: Invalid dimensions." << endl;
            return 1;
        }

        cout << "Enter matrix elements:" << endl;
        readMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);

        transposeMatrix(matrix, result, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        // ---------------- PART B: ADD ----------------
        int rows, cols;
        int matA[MAX_SIZE][MAX_SIZE];
        int matB[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
            cout << "Error: Invalid dimensions." << endl;
            return 1;
        }

        cout << "Enter elements of Matrix A:" << endl;
        readMatrix(matA, rows, cols);

        cout << "Enter elements of Matrix B:" << endl;
        readMatrix(matB, rows, cols);

        cout << "\nMatrix A:" << endl;
        printMatrix(matA, rows, cols);

        cout << "\nMatrix B:" << endl;
        printMatrix(matB, rows, cols);

        addMatrices(matA, matB, result, rows, cols);

        cout << "\nSum (A + B):" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        // ---------------- PART C: MULTIPLY ----------------
        int m, n, n2, p;
        int matA[MAX_SIZE][MAX_SIZE];
        int matB[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A (N): ";
        cin >> n;

        if (m <= 0 || n <= 0 || m > MAX_SIZE || n > MAX_SIZE) {
            cout << "Error: Invalid dimensions for Matrix A." << endl;
            return 1;
        }

        cout << "Enter elements of Matrix A:" << endl;
        readMatrix(matA, m, n);

        cout << "Enter rows of Matrix B (must equal N = " << n << "): ";
        cin >> n2;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        if (n2 != n) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 1;
        }

        if (p <= 0 || p > MAX_SIZE) {
            cout << "Error: Invalid dimensions for Matrix B." << endl;
            return 1;
        }

        cout << "Enter elements of Matrix B:" << endl;
        readMatrix(matB, n, p);

        cout << "\nMatrix A:" << endl;
        printMatrix(matA, m, n);

        cout << "\nMatrix B:" << endl;
        printMatrix(matB, n, p);

        multiplyMatrices(matA, matB, result, m, n, p);

        cout << "\nProduct (A x B):" << endl;
        printMatrix(result, m, p);

    } else {
        cout << "Error: Invalid choice." << endl;
        return 1;
    }

    return 0;
}

// Reads values into a matrix, element by element
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Computes the transpose of a matrix (rows become columns)
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// Adds two matrices of the same dimensions element-wise
void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// Multiplies an M x N matrix by an N x P matrix, producing an M x P result
void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matA[i][k] * matB[k][j];
            }
            result[i][j] = sum;
        }
    }
}