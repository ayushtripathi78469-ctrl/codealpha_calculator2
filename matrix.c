
#include <stdio.h>

#define MAX 10

void inputMatrix(int a[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX],
                 int r, int c) {
    int i, j, result[MAX][MAX];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Addition:\n");
    displayMatrix(result, r, c);
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k, result[MAX][MAX] = {0};

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication:\n");
    displayMatrix(result, r1, c2);
}

void transposeMatrix(int a[MAX][MAX], int r, int c) {
    int i, j, result[MAX][MAX];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            result[j][i] = a[i][j];
        }
    }

    printf("Transpose:\n");
    displayMatrix(result, c, r);
}

int main(void) {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Transpose of Matrix A\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
        printf("Invalid matrix dimensions!\n");
        return 0;
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(a, r1, c1);

    if (choice == 3) {
        transposeMatrix(a, r1, c1);
    } else {
        printf("Enter rows and columns of Matrix B: ");
        scanf("%d %d", &r2, &c2);

        if (r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
            printf("Invalid matrix dimensions!\n");
            return 0;
        }

        printf("Enter elements of Matrix B:\n");
        inputMatrix(b, r2, c2);

        if (choice == 1) {
            if (r1 == r2 && c1 == c2) {
                addMatrices(a, b, r1, c1);
            } else {
                printf("Addition requires equal dimensions!\n");
            }
        } else if (choice == 2) {
            if (c1 == r2) {
                multiplyMatrices(a, b, r1, c1, c2);
            } else {
                printf("Columns of A must equal rows of B!\n");
            }
        }
    }

    return 0;
}
