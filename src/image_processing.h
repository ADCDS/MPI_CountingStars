//
// Created by Turox on 7/16/2018.
//

#ifndef PP_FINAL_IMAGE_PROCESSING_H
#define PP_FINAL_IMAGE_PROCESSING_H

/**
 * Given an binarized matrix, count how many objects are there
 * Implemented from https://courses.cs.washington.edu/courses/cse576/book/ch3.pdf
 * @param img
 * @param row
 * @param col
 * @return
 */
int count_objects(int * img, int row, int col);

/**
 * Given an matrix, binarize it by a factor (1 if element >= factor, 0 otherwise)
 * @param img
 * @param row
 * @param col
 */
void binarize(int *img, int row, int col, int factor);

#endif //PP_FINAL_IMAGE_PROCESSING_H
