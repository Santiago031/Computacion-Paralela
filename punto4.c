#include <stdio.h>
#include <stdlib.h>

// Función para imprimir una matriz
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &rows);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &cols);

    // Reservar memoria para la matriz
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Error al asignar memoria para las filas de la matriz.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Error al asignar memoria para las columnas de la matriz.\n");
            return 1;
        }
    }

    // Inicializar la matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    // Imprimir la matriz
    printf("La matriz generada es:\n");
    printMatrix(matrix, rows, cols);

    // Liberar la memoria
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
