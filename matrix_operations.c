#include <stdio.h>

int acceptMatrix(int matrix[20][20], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    return 0;
}

int displayMatrix(int matrix[20][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    return 0;
}

int compactMatrix(int matrix[20][20], int rows, int cols, int compact[20][3]) {
    int k = 1;
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
    }
    compact[0][2] = k - 1;
    return k;
}

void displayCompactMatrix(int compact[20][3], int compactRows) {
    printf("Rows\tColumns\tValue\n");
    for (int i = 0; i < compactRows; i++)
        printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
}

void simpleTranspose(int compact[20][3], int simpleTransposed[20][3], int compactRows) {
    simpleTransposed[0][0] = compact[0][1];
    simpleTransposed[0][1] = compact[0][0];
    simpleTransposed[0][2] = compact[0][2];

    int k = 1;
    for (int col = 0; col < compact[0][1]; col++)
        for (int i = 1; i < compactRows; i++)
            if (compact[i][1] == col) {
                simpleTransposed[k][0] = compact[i][1];
                simpleTransposed[k][1] = compact[i][0];
                simpleTransposed[k][2] = compact[i][2];
                k++;
            }
}

void fastTranspose(int compact[20][3], int fastTransposed[20][3], int compactRows) {
    int rowTerms[20], startingPos[20];
    int i, j, numCols = compact[0][1], numTerms = compact[0][2];

    fastTransposed[0][0] = numCols;
    fastTransposed[0][1] = compact[0][0];
    fastTransposed[0][2] = numTerms;

    for (i = 0; i < numCols; i++)
        rowTerms[i] = 0;

    for (i = 1; i <= numTerms; i++)
        rowTerms[compact[i][1]]++;

    startingPos[0] = 1;
    for (i = 1; i < numCols; i++)
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];

    for (i = 1; i <= numTerms; i++) {
        j = startingPos[compact[i][1]]++;
        fastTransposed[j][0] = compact[i][1];
        fastTransposed[j][1] = compact[i][0];
        fastTransposed[j][2] = compact[i][2];
    }
}

int main() {
    int matrix[20][20];
    int compact[20][3];
    int simpleTransposed[20][3];
    int fastTransposed[20][3];
    int rows, cols, compactRows;
    int choice;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);
    acceptMatrix(matrix, rows, cols);

    do {
        printf("\nMenu:\n");
        printf("1. Display Original Matrix\n");
        printf("2. Display Compact Matrix\n");
        printf("3. Display Simple Transpose\n");
        printf("4. Display Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nOriginal Matrix:\n");
                displayMatrix(matrix, rows, cols);
                break;
            case 2:
                compactRows = compactMatrix(matrix, rows, cols, compact);
                printf("\nCompact Matrix:\n");
                displayCompactMatrix(compact, compactRows);
                break;
            case 3:
                simpleTranspose(compact, simpleTransposed, compactRows);
                printf("\nSimple Transpose of Compact Matrix:\n");
                displayCompactMatrix(simpleTransposed, compactRows);
                break;
            case 4:
                fastTranspose(compact, fastTransposed, compactRows);
                printf("\nFast Transpose of Compact Matrix:\n");
                displayCompactMatrix(fastTransposed, compactRows);
                break;
            case 5:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice. Enter a number between 1-5. \n");
        }
    } while (choice != 5);

    return 0;
}
