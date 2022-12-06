#include <stdio.h>
#include <mpi.h>
#define N 1000
//Main function
int main(int argc, char *argv[]){
int pid,nprocs,i,j;
int sum, data;
 MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
   MPI_Comm_rank(MPI_COMM_WORLD,&pid );
    sum = 0;
    //initialize status variable
    MPI_Status* stats[nprocs];
    //initialize request variable
    MPI_Request reqs[nprocs];
    //Logic to print the total values for each slot of partial sum
    for (i=1;i< 101;i++){
    sum = sum + i + pid * 100;
    }
    //Printing the partial sum values
    printf("Partial sum from process %d of total %d is : %d\n", pid,nprocs,sum);
    /*send and receive - non blocking */
    //Condition to check if the current process is 0
    if (pid == 0){
    for (i= 1; i< 10; i++){
    //collect the partial sums from other processes
    MPI_Irecv(&data, 1, MPI_INT, i, 0, MPI_COMM_WORLD,&reqs[i]);
    MPI_Wait(&reqs[i],MPI_STATUS_IGNORE);
    //Printing the received values from other process to process 0
    printf("Receive %d from process %d\n", data, i);
    //Calculating the sum
    sum = sum + data;
    }
    //printing the total sum
    printf("Total sum is %d", sum);
    }
   //if the current process is not equal 0
   else{
    //Sending the value to process 0
    MPI_Isend(&sum, 1, MPI_INT, 0, 0,MPI_COMM_WORLD,&reqs[pid]);
    //printing the values that are sent to process 0
    printf("Send %d to process 0 by process %d\n", sum,pid);
    }
    //End of MPI commands
    MPI_Finalize();
    return 0;
    }
     