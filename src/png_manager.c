//
// Created by Turox on 7/17/2018.
//

#include <libpng/png.h>
#include <stdlib.h>

#include "png_manager.h"

struct png_file read_png(char *file_name) {
    int x, y;

    int width, height;
    png_byte color_type;
    png_byte bit_depth;

    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep *row_pointers;


    char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(file_name, "rb");

    fread(header, 1, 8, fp);
    /* initialize stuff */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);


    info_ptr = png_create_info_struct(png_ptr);

    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);

    width = png_get_image_width(png_ptr, info_ptr);
    height = png_get_image_height(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    number_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);


    /* read file */

    row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * height);
    for (y = 0; y < height; y++)
        row_pointers[y] = (png_byte *) malloc(png_get_rowbytes(png_ptr, info_ptr));

    png_read_image(png_ptr, row_pointers);

    fclose(fp);

    int *data = malloc(sizeof(int) * width * height);
    for (y = 0; y < height; y++) {
        png_byte *row = row_pointers[y];
        for (x = 0; x < width; x++) {
            png_byte *ptr = &(row[x * 4]);

            data[y * width + x] =  ptr[0];
        }
    }

    for (y = 0; y < height; y++)
        free(row_pointers[y]);
    free(row_pointers);

    struct png_file res = { .width = width, .height = height, .data = data};
    return res;
}