#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


 //if (world_rank == 0) {
 // If we are the root process, send our data to everyone
//    int i;
//    for (i = 0; i < world_size; i++) {
//      if (i != world_rank) {

//        MPI_Bcast(&token, strlen(token), MPI_BYTE, 0, MPI_COMM_WORLD);

//            }
//      }
//  }  else {
        // If we are a receiver process, receive the data from the root
     MPI_Bcast(&token, strlen(token), MPI_BYTE, 0, MPI_COMM_WORLD);
    printf("Process %d received token %s \n", world_rank, 
token);

  
MPI_Finalize();
}

