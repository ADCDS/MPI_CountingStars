//
// Created by Turox on 7/18/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/matrix.h"

int main(){
    int mat[4][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16},
    };
    int width = 4;
    int height = 4;

    print(&mat, width, 4, 4);

    int current_I = 0, current_J = 0;
    int block_size = 2;

    while( current_I < width){
        while(current_J < height){
            printf("RANK 0: Sending %d bytes POS{X: %d,Y: %d}\n", block_size * block_size, current_I, current_J);
            fflush(stdout);
            int *extracted = extract_zf(&mat, current_I, current_J, height, width, block_size,
                                        block_size);
            print(extracted, block_size, block_size, block_size);
            fflush(stdout);
            free(extracted);
            current_J += block_size;

        }
        current_J = 0;
        current_I += block_size;
    }

}