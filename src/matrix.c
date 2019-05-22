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

int *extract_zf(const int * a, int offset_i, int offset_j, int row_size, int col_size, int row, int col) {
    int *output = (int *) malloc(sizeof(int) * row * col);
    int i, j;
	
  for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if ((i + offset_i) * col_size + (j + offset_j) < row_size * col_size) {
                /* printf("a[%d], offset_i: %d, offset_j: %d, row_size %d, col_size: %d, a[%d][%d]",
                       (i + offset_i) * col_size + (j + offset_j), offset_i, offset_j, row_size, col_size, i + offset_i,
                       j + offset_j);
		fflush(stdout);
		*/
                output[i * col + j] = a[(i + offset_i) * col_size + (j + offset_j)];
		//printf(" - ok\n");
            } else {
                output[i * col + j] = 0;
            }
        }
    }

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
