//
// Created by Turox on 7/17/2018.
//

#include <stdio.h>
#include "../src/png_manager.h"
#include "../src/image_processing.h"

int main(){
    printf("PNG Manager test:\n\n");
    printf("Reading image... ");
    struct png_file file = read_png("../images/blood.png");
    printf("Done\nBinarizing image... ");
    binarize(file.data, file.height, file.width, 128);
    printf("Done\nCounting objects... ");
    printf("%d objects in the image.", count_objects(file.data, file.height, file.width));
}