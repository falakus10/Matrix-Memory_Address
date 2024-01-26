#include <stdio.h>
#include <stdlib.h>

void takeMatrixInput(int **matrix, int rowNumber, int columnNumber);
void printMatrix(int **matrix, int rowSize, int columnSize);

int main() {
    int row, column, number = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &column);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; ++i) {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }

    if (matrix == NULL) {
        printf("Memory allocation failed for the array.\n");
        exit(0);
    } else {
        for (int i = 0; i < row; ++i) {
            printf("Memory address of each row: %p\n", (void *)matrix[i]);
        }
    }

    takeMatrixInput(matrix, row, column);

    printMatrix(matrix, row, column);

    for (int i = 0; i < row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void takeMatrixInput(int **matrix, int rowNumber, int columnNumber) {
    int number = 0;
    for (int i = 0; i < rowNumber; ++i) {
        for (int j = 0; j < columnNumber; ++j) {
            matrix[i][j] = ++number;
        }
    }
}

void printMatrix(int **matrix, int rowSize, int columnSize) {
    printf("Matrix:\n");
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < columnSize; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}