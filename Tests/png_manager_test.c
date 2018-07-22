//
// Created by Turox on 7/17/2018.
//

#include <stdio.h>
#include "../src/png_manager.h"

int main(){
    printf("PNG Manager test");
    struct png_file file = read_png("../images/2x2_0_objects.png");
    printf("Image read");
}