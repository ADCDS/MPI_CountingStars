//
// Created by Turox on 7/17/2018.
//

#ifndef PP_FINAL_PNG_MANAGER_H
#define PP_FINAL_PNG_MANAGER_H

struct png_file{
    int width;
    int height;
    int * data;
};

/**
 * png_file.data is a vector with only the red values from a PNG image
 * @param file_name
 * @return
 */
struct png_file read_png(char* file_name);

#endif //PP_FINAL_PNG_MANAGER_H
