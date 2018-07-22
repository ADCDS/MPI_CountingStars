//
// Created by Turox on 7/16/2018.
//

#include "image_processing.h"

int count_objects(int *img, int row, int col) {
    int external_corners[4][4] = {
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 0}
    };
    int internal_corners[4][4] = {
            {1, 1, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 1},
            {0, 1, 1, 1}
    };
    int E = 0, I = 0;
    int i, j;
    for (i = 0; i < row - 1; ++i) {
        for (j = 0; j < col - 1; ++j) {
            int k = 0;
            //Match an external corner
            while (k < 4) {
                // Structural element
                int *structural_element = &external_corners[k][0];
                int l;
                for (l = 0; l < 2; ++l) {
                    int m;
                    for (m = 0; m < 2; ++m) {
                        if (structural_element[l * 2 + m] != img[(i + l) * col + (j + m)])
                            goto next_filter;
                    }
                }
                E++;

                next_filter:
                k++;
            }


            //Match an internal corner
            k = 0;
            while (k < 4) {
                // Structural element
                int *structural_element = &internal_corners[k][0];
                int l;
                for (l = 0; l < 2; ++l) {
                    int m;
                    for (m = 0; m < 2; ++m) {
                        if (structural_element[l * 2 + m] != img[(i + l) * col + (j + m)])
                            goto next_filter2;
                    }
                }
                I++;

                next_filter2:
                k++;
            }
        }
    }
    return (E - I)/4;
};

void binarize(int *img, int row, int col, int factor) {
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (img[i * col + j] >= factor) {
                img[i * col + j] = 1;
            } else {
                img[i * col + j] = 0;
            }
        }
    }
};
