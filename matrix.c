//
// Created by Turox on 7/16/2018.
//
#include <malloc.h>


int *extract(const int * a, int col_size, int row, int col) {
    int *output = (int *) malloc(sizeof(int) * row * col);
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            output[i * col + j] = a[i * col_size + j];

    return output;
}

void print(int *a, int col_size, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%3d ", a[i * col_size + j]);
        printf("\n");
    }
}