//
// Created by Turox on 7/17/2018.
//

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/png_manager.h"
#include "../src/matrix.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Please provide an block size");
        exit(1);
    }

    int block_size = atoi(argv[1]);
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    MPI_RECV
    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    if(world_rank == 0){//Main process
        printf("RANK 0: Reading PNG\n");
        struct png_file file = read_png("../images/1055x575_6_objects.png");
        if(file.width % block_size != 0 || file.height % block_size != 0) {
            printf("Invalid block size");
            exit(255);
        }

        for (int i = 1; i < world_size; ++i) {
            int * new_matrix = extract((&file.data[]), file.width, block_size, block_size);
            MPI_Isend(&number, 1, MPI_INT, 1-world_rank, 0, MPI_COMM_WORLD);
        }
    }else{

    }

    // Finalize the MPI environment.
    MPI_Finalize();
}