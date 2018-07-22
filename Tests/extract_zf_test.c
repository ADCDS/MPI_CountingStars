//
// Created by Turox on 7/18/2018.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/png_manager.h"
#include "../src/matrix.h"
#include "../src/image_processing.h"

int main(){
    struct png_file file = read_png("../images/100x100.png");
    int current_I = 0, current_J = 0;
    int block_size = 15;

    while( current_I < file.width){
        while(current_J < file.height){
            printf("RANK 0: Sending %d bytes POS{X: %d,Y: %d}\n", block_size * block_size, current_I, current_J);
            int *extracted = extract_zf((&file.data[current_J * file.width + current_I]), current_J * file.width + current_I, file.height, file.width, block_size,
                                        block_size);

            free(extracted);
            current_J += block_size;

        }
        current_J = 0;
        current_I += block_size;
    }

}