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

 if (world_rank == 0) {
 // If we are the root process, send our data to everyone
    int i;
    for (i = 0; i < world_size; i++) {
      if (i != world_rank) {

        MPI_Barrier(MPI_COMM_WORLD);
        total_mpi_bcast_time -= MPI_Wtime();
        MPI_Bcast(&token, strlen(token), MPI_BYTE, 0, MPI_COMM_WORLD);
        MPI_Barrier(MPI_COMM_WORLD);
        total_mpi_bcast_time += MPI_Wtime();
            }

      }
  }  else {
        // If we are a receiver process, receive the data from the root
     MPI_Bcast(&token, strlen(token), MPI_BYTE, 0, MPI_COMM_WORLD);
    printf("Process %d received token %s from process %d, time is %f\n", 
world_rank, token,
           world_rank - 1, total_mpi_bcast_time);

  }
MPI_Finalize();
}
