#include <stdio.h>

#include "../src/matrix.h"
#include "../src/image_processing.h"

int main() {
    int a[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    /**
    int i, j;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            a[i][j] = i * 10 + j;
            **/

    print((&a[0][0]), 10, 10, 10);

    printf("\n\n");

    /*
    print((&a[4][3]), 10, 5, 4);


    printf("\n\n Printing extracted matrix\n");
    int *b = extract((&a[4][3]), 10, 5, 4);
    print(b, 4, 5, 4);

    printf("\n\n Printing binarized matrix\n");
    binarize(b, 5, 4, 1);
    print(b, 4, 5, 4);
     */

    printf("\n\n How many 1's in matrix %d\n", count_objects(&a[0][0], 10, 10));

    return 0;
}