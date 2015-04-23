#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

 char token[100];
 strcpy(token, argv[1]);

if (argc != 2) {
    fprintf(stderr, "Usage: compare_bcast num_elements num_trials\n");
    exit(1);
  }

 

  double total_mpi_bcast_time = 0.0;

        MPI_Barrier(MPI_COMM_WORLD);
        total_mpi_bcast_time -= MPI_Wtime();
        MPI_Bcast(&token, strlen(token), MPI_BYTE, 0, MPI_COMM_WORLD);
        MPI_Barrier(MPI_COMM_WORLD);
        total_mpi_bcast_time += MPI_Wtime();
        printf("Process %d received token %s , using time: %f\n", 
world_rank, token,
          total_mpi_bcast_time);


MPI_Finalize();
}

