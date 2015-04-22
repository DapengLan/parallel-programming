// a game of Telephone
// author : Dapeng Lan
// Time	  : 22/4/2015

#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv) {
    
    MPI_Init(NULL,NULL); // Initial the MPI environment
    
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); //Get the number of the processor

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);  // Get the rank of the processor 

    int token;
    if (world_rank !=0) {
	MPI_Recv(&token, 1, MPI_INT, (world_rank - 1), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf(" Process %d received token %d from process %d\n", world_rank, token, world_rank -1);
	}
   else { 
	token = -1;  // set the value token	
	}
MPI_Send(&token, 1 , MPI_INT, (world_rank + 1) % world_size, 0 , MPI_COMM_WORLD); // every processor is sending to the nex

//process 0 can receice from the last process. 

if (world_rank == 0 ){
	MPI_Recv(&token, 1, MPI_INT, world_size -1 ,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf(" Process %d received token %d from process %d\n", world_rank, token, world_size -1);
}
	MPI_Finalize();
}




